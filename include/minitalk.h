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

int		ft_strlen(char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

#endif
