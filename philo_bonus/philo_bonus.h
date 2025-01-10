#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
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
	sem_t			*forks_sem;
	sem_t			*print_sem;
}	t_vars;

typedef struct s_philo
{
	int				nbr;
	time_t			last_meal;
	size_t			eat_times;
	pid_t			id;
}	t_philo;

t_philo	**ft_philos_init(t_vars vars);
size_t	ft_atoi(char *str, int *error);
void	free_until(t_philo **philos, int until, t_vars *vars);
void	ft_usleep(size_t ms, t_philo *philo, t_vars vars);
time_t	ft_current_time();
int		ft_prase_vars(int argc, char **argv, t_vars *vars);
int		ft_philo(t_vars vars);
void	ft_print(t_philo *philo, t_vars vars, char *msg);
int		ft_eat(t_philo *philo, t_vars vars);
void	ft_sleep(t_philo *philo, t_vars vars);
void	ft_think(t_philo *philo, t_vars vars);

#endif