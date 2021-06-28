#include "minitalk.h"

void	get_client_pid(int sig, t_data *data)
{
	if (sig == SIGUSR1)
	{
		data->client_pid += 1 << data->i;
	}
	data->i++;
	if (data->i == 32)
	{
		data->i = 0;
		ft_putstr("Client PID: ");
		ft_putnbr(data->client_pid);
		ft_putstr("\n");
		data->got_pid = true;
	}
	return ;
}

void	get_char(int sig, t_data *data)
{
	if (sig == SIGUSR1)
		data->c += 1 << data->i;
	data->i++;
	if (data->i == 8)
	{
		if (data->c == '\0')
		{
			write(1, "\n", 1);
			usleep(200);
			kill(data->client_pid, SIGUSR1);
			data->client_pid = 0;
			data->got_pid = false;
		}
		else
			write(1, &data->c, 1);
		data->i = 0;
		data->c = 0;
	}
}

void	handler(int sig)
{
	static t_data	data = {0, 0, false, 0};

	if (data.got_pid == false)
		get_client_pid(sig, &data);
	else
		get_char(sig, &data);
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
