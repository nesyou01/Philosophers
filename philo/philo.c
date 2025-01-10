#include "philo.h"

static int	ft_should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->vars->m_stop);
	stop = philo->vars->stop;
	pthread_mutex_unlock(&philo->vars->m_stop);
	return (stop);
}

static void	*philo_rotine(void *attrs)
{
	t_philo		*philo;
	pthread_t	death_id;

	philo = (t_philo *) attrs;
	if (philo->nbr % 2 == 0)
		ft_usleep(philo->vars->time_to_sleep / 5, philo);
	while (!ft_should_stop(philo))
	{
		if (pthread_create(&death_id, NULL, &death_rotine, philo) != 0)
			return (NULL);
		pthread_detach(death_id);
		if (ft_eat(philo))
			break ;
		ft_sleep(philo);
		ft_think(philo);
		if (philo->eat_times != -1 && philo->eat_times >= philo->vars->max_eat)
			break ;
	}
	return (NULL);
}

int	ft_philo(t_vars vars)
{
	t_philo	**philos;
	int		i;

	philos = ft_philos_init(vars);
	if (!philos)
		return (free_until(NULL, 0, &vars), 2);
	i = 0;
	vars.started_at = ft_current_time();
	while (i < vars.philos)
	{
		philos[i]->vars = &vars;
		if (pthread_create(&philos[i]->id, NULL, &philo_rotine, philos[i]) != 0)
			return (free_until(philos, vars.philos, &vars), 4);
		i++;
	}
	i = 0;
	while (i < vars.philos)
	{
		if (pthread_join(philos[i++]->id, NULL) != 0)
			return (free_until(philos, vars.philos, &vars), 5);
	}
	free_until(philos, vars.philos, &vars);
	return (0);
}
