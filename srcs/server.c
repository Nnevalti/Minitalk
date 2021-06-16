#include "minitalk.h"

void	handler(int sig)
{
	static int		i = 0;
	static char		c = 0;
	static int		pid_client = 0;
	static t_bool	got_pid = 0;

	if (got_pid == false)
	{
		if (sig == SIGUSR1)
			pid_client += 1 << i;
		i++;
		if (i == 32)
		{
			i = 0;
			ft_putstr("Client PID: ");
			ft_putnbr(pid_client);
			ft_putstr("\n");
			got_pid = true;
		}
	}
	else
	{
		if (sig == SIGUSR1)
			c += 1 << i;
		i++;
		if (i == 8)
		{
			if (c == '\0')
			{
				write(1, "\n", 1);
				usleep(200);
				kill(pid_client, SIGUSR1);
				pid_client = 0;
				got_pid = false;
			}
			else
				write(1, &c, 1);
			i = 0;
			c = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
	{
	}
	return (0);
}
