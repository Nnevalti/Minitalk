#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (value * sign);
}

void send_char(pid_t pid, char c)
{
	int i = 0;

	while (i < 8)
	{
		usleep(200);
		if (c & 0b00000001)
		{
			kill(pid, SIGUSR1);
			printf("1");
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("0");
		}
		c = c >> 1;
		i++;
	}
	printf("\n");
}

void send_string(pid_t pid, char *msg)
{
	int i = 0;

	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, msg[i]);
}

int main(int ac, char **av) {
	pid_t pid;

	if (ac != 3)
	{
		printf("Error: Usage ./client server_PID message\n");
	}
	else
	{
		pid = getpid();
		// send_pid();
		printf("PID = %d\n", pid);
		send_string(ft_atoi(av[1]), av[2]);
	}
	return 0;
}
