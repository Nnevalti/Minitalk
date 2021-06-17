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

void	send_pid(pid_t pid, pid_t server_pid)
{
	int	i;

	ft_putstr("Client PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	i = 0;
	while (i < 32)
	{
		usleep(50);
		if (pid & 0b00000001)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		pid = pid >> 1;
		i++;
	}
}

void	ack(int sig)
{
	(void)sig;
	ft_putstr("[ACK] Message received.\n");
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr("Error: Usage ./client server_PID message\n");
		exit(0);
	}
	else
	{
		signal(SIGUSR1, ack);
		pid = getpid();
		send_pid(pid, ft_atoi(av[1]));
		send_string(ft_atoi(av[1]), av[2]);
	}
	pause();
	return (0);
}
