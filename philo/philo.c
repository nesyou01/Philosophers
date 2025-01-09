#include "philo.h"

static void	free_until(t_philo **philos, int until)
{
	int		i;

	i = 0;
	while (i < until)
		free(philos[i++]);
	free(philos);
}
static void	init_forks(t_philo **philos, t_vars vars)
{
	int		i;

	i = 0;
	while (i < vars.philos)
	{
		pthread_mutex_init(&philos[i]->fork, NULL);
		if (i == vars.philos - 1)
			philos[i]->r_fork = &philos[0]->fork;
		else
			philos[i]->r_fork = &philos[i + 1]->fork;
		i++;
	}
}

static t_philo	**ft_philos_init(t_vars vars)
{
	t_philo	**result;
	t_philo	*philo;
	int		i;

	i = 0;
	result = (t_philo **) malloc(vars.philos * sizeof(t_philo));
	if (!result)
		return (NULL);
	while (i < vars.philos)
	{
		philo = (t_philo *) malloc(sizeof(t_philo));
		if (!philo)
			return (free_until(result, i), NULL);
		philo->eat_times = 0;
		philo->nbr = i + 1;
		result[i++] = philo;
	}
	init_forks(result, vars);
	return (result);
}

int	ft_should_stop(t_philo *philo)
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

	philo = (t_philo *) attrs;
	if (philo->nbr % 2 == 0)
		usleep(philo->vars->time_to_sleep / 5);
	while (!ft_should_stop(philo))
	{
		ft_eat(philo);
		if (!philo->vars->stop)
		{
			ft_sleep(philo);
			ft_think(philo);
		}
		if (philo->eat_times != -1 && philo->eat_times >= philo->vars->max_eat)
			break ;
	}
	return (NULL);
}

int	ft_philo(t_vars vars)
{
	t_philo	**philos;
	int		i;

	pthread_mutex_init(&vars.m_stop, NULL);
	pthread_mutex_init(&vars.m_print, NULL);
	philos = ft_philos_init(vars);
	if (!philos)
		return (2);
	i = 0;
	vars.started_at = ft_current_time();
	while (i < vars.philos)
	{
		philos[i]->vars = &vars;
		pthread_create(&philos[i]->id, NULL, &philo_rotine, philos[i]);
		i++;
	}
	i = 0;
	while (i < vars.philos)
		pthread_join(philos[i++]->id, NULL);
	return (0);
}
