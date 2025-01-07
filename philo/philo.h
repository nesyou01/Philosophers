#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_vars
{
	unsigned int	philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				max_eat;
}	t_vars;

typedef struct s_philo
{
	int				nbr;
	pthread_t		id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*r_fork;
	t_vars			*vars;
}	t_philo;

int		ft_prase_vars(int argc, char **argv, t_vars *vars);
size_t	ft_atoi(char *str, int *error);
int		ft_philo(t_vars vars);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);


#endif