#include "philo.h"

void	*death_rotine(void *attrs)
{
	t_philo		*philo;

	philo = (t_philo *) attrs;
	ft_usleep(philo->vars->time_to_die, philo);
	if (pthread_mutex_lock(&philo->vars->m_stop) != 0)
		return (NULL);
	if (!philo->vars->stop && ft_current_time() - philo->last_meal >= philo->vars->time_to_die)
	{
		ft_print(philo, "died");
		philo->vars->stop = 1;
	}
	pthread_mutex_unlock(&philo->vars->m_stop);
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->r_fork) != 0)
		return (1);
	ft_print(philo, "has taken a fork");
	if (pthread_mutex_lock(&philo->fork) != 0)
		return (1);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->eat_times++;
	if (pthread_mutex_lock(&philo->vars->m_stop) != 0)
		return (1);
	philo->last_meal = ft_current_time();
	if (pthread_mutex_unlock(&philo->vars->m_stop) != 0)
		return (1);
	ft_usleep(philo->vars->time_to_eat, philo);
	if (pthread_mutex_unlock(philo->r_fork) != 0)
		return (1);
	if (pthread_mutex_unlock(&philo->fork) != 0)
		return (1);
	return (0);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->vars->time_to_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}
