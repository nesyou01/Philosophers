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
	printf("%zd %d %s\n", ft_current_time() - philo->vars->started_at, philo->nbr, msg);
}

void	ft_usleep(size_t ms, t_philo *philo)
{
	time_t	time;

	time = ft_current_time();
	while (ft_current_time() - time < ms && !philo->vars->stop)
		usleep(ms / 10);
}
