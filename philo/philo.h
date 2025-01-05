#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_vars
{
	unsigned int	number_of_philosopher;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				max_eat;
}	t_vars;

int		ft_prase_vars(int argc, char **argv, t_vars *vars);
size_t	ft_atoi(char *str, int *error);

#endif