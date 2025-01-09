#include "philo.h"

time_t	ft_current_time()
{
	struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void	ft_print(t_philo *philo, char *msg)
{
	if (philo->vars->stop)
		return ;
	pthread_mutex_lock(&philo->vars->m_print);
	printf("%zd %d %s\n", ft_current_time() - philo->vars->started_at, philo->nbr, msg);
	pthread_mutex_unlock(&philo->vars->m_print);
}

void	ft_usleep(size_t ms, t_philo *philo)
{
	time_t	time;

	time = ft_current_time();
	while (ft_current_time() - time < ms && !philo->vars->stop)
		usleep(ms / 10);
}

void	free_until(t_philo **philos, int until)
{
	int		i;

	i = 0;
	while (i < until)
		free(philos[i++]);
	free(philos);
}
