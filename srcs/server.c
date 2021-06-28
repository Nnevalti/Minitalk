#include "minitalk.h"

void	get_char(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			usleep(200);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	handler(int sig)
{
	get_char(sig);
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
