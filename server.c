#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int sig)
{
	static int i = 0;
	static char c = 0;

	if (sig == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;

	}
}

int main() {
	pid_t	pid;

	pid = getpid();
	printf("PID = %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42){}
	return 0;
}
