#include "philo_bonus.h"

time_t	ft_current_time()
{
	struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_print(t_philo *philo, t_vars vars, char *msg)
{
	if (vars.stop)
		return ;
	if (sem_wait(vars.print_sem) != 0)
		return ;
	printf("%zd %d %s\n", ft_current_time() - vars.started_at, philo->nbr, msg);
	sem_post(vars.print_sem);
}

void	ft_usleep(size_t ms, t_philo *philo, t_vars vars)
{
	time_t	time;

	time = ft_current_time();
	while (ft_current_time() - time < ms  && !vars.stop)
		usleep(ms / 10);
}

void	free_until(t_philo **philos, int until, t_vars *vars)
{
	int		i;

	i = 0;
	if (!philos)
		return ;
	while (i < until)
		free(philos[i++]);
	free(philos);
}
