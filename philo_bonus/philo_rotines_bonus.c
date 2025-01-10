#include "philo_bonus.h"

// void	*death_rotine(void *attrs)
// {
// 	t_philo		*philo;

// 	philo = (t_philo *) attrs;
// 	ft_usleep(philo->vars->time_to_die, philo);
// 	if (pthread_mutex_lock(&philo->vars->m_stop) != 0)
// 		return (NULL);
// 	if (!philo->vars->stop && ft_current_time() - philo->last_meal >= philo->vars->time_to_die)
// 	{
// 		ft_print(philo, "died");
// 		philo->vars->stop = 1;
// 	}
// 	pthread_mutex_unlock(&philo->vars->m_stop);
// 	return (NULL);
// }

int	ft_eat(t_philo *philo, t_vars vars)
{
	if (sem_wait(vars.forks_sem) != 0)
		return (1);
	ft_print(philo, vars, "has taken a fork");
	if (sem_wait(vars.forks_sem) != 0)
		return (1);
	ft_print(philo, vars, "has taken a fork");
	ft_print(philo, vars, "is eating");
	philo->eat_times++;
	philo->last_meal = ft_current_time();
	ft_usleep(vars.time_to_eat, philo, vars);
	if (sem_post(vars.forks_sem) != 0)
		return (1);
	if (sem_post(vars.forks_sem) != 0)
		return (1);
	return (0);
}

void	ft_sleep(t_philo *philo, t_vars vars)
{
	ft_print(philo, vars, "is sleeping");
	ft_usleep(vars.time_to_sleep, philo, vars);
}

void	ft_think(t_philo *philo, t_vars vars)
{
	ft_print(philo, vars, "is thinking");
}
