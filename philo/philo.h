#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
#include <unistd.h>

typedef struct s_vars
{
	unsigned int	number_of_philosopher;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				max_eat;
}	t_vars;

typedef struct s_philo
{
	int				nbr;
	pthread_mutex_t	fork;
	pthread_t		id;
}	t_philo;

int		ft_prase_vars(int argc, char **argv, t_vars *vars);
size_t	ft_atoi(char *str, int *error);

#endif