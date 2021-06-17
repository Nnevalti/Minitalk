#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_data
{
	int		i;
	char	c;
	t_bool	got_pid;
	pid_t	client_pid;
}			t_data;

int		ft_strlen(const char *str);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

#endif
