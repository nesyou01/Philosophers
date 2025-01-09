#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_vars
{
	unsigned int	philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				max_eat;
	int				stop;
	time_t			started_at;
	pthread_mutex_t	m_stop;
}	t_vars;

typedef struct s_philo
{
	int				nbr;
	pthread_t		id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*r_fork;
	t_vars			*vars;
	time_t			last_meal;
}	t_philo;

int		ft_prase_vars(int argc, char **argv, t_vars *vars);
size_t	ft_atoi(char *str, int *error);
int		ft_philo(t_vars vars);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
time_t	ft_current_time();
void	ft_usleep(size_t ms, t_philo *philo);
void	ft_print(t_philo *philo, char *msg);

#endif