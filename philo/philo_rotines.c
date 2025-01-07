#include "philo.h"

static void	ft_print(t_philo *philo, char *msg)
{
	printf("%zd %d %s\n", ft_current_time() - philo->vars->started_at, philo->nbr, msg);
}

static void	ft_usleep(size_t ms)
{
	usleep(ms * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	ft_usleep(philo->vars->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->vars->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}
