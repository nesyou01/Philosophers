#include "philo.h"

static void	*death_rotine(void *attrs)
{
	t_philo		*philo;

	philo = (t_philo *) attrs;
	ft_usleep(philo->vars->time_to_die, philo);
	pthread_mutex_lock(&philo->vars->m_stop);
	if (ft_current_time() - philo->last_meal >= philo->vars->time_to_die && !philo->vars->stop)
	{
		ft_print(philo, "died");
		philo->vars->stop = 1;
	}
	pthread_mutex_unlock(&philo->vars->m_stop);
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_t	death_id;

	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	pthread_mutex_lock(&philo->vars->m_stop);
	philo->last_meal = ft_current_time();
	pthread_mutex_unlock(&philo->vars->m_stop);
	pthread_create(&death_id, NULL, &death_rotine, philo);
	// pthread_detach(death_id);
	ft_usleep(philo->vars->time_to_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->fork);
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
