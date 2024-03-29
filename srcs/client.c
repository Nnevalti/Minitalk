#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(50);
		if (c & 0b00000001)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
	}
}

void	send_string(const pid_t pid, const char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, msg[i]);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr("Error: Usage ./client server_PID message\n");
		exit(0);
	}
	else
		send_string(ft_atoi(av[1]), av[2]);
	return (0);
}
