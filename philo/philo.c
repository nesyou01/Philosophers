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
		pthread_mutex_init(&philos[0]->fork, NULL);
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
		result[i++] = philo;
	}
	init_forks(result, vars);
	return (result);
}

static void	*philo_rotine(void *attrs)
{
	t_philo *philo;

	philo = (t_philo *) attrs;
	if (philo->nbr % 2 == 0)
		usleep(philo->vars->time_to_sleep / 5);
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	ft_philo(t_vars vars)
{
	t_philo	**philos;
	t_philo *philo;
	int		i;

	philos = ft_philos_init(vars);
	if (!philos)
		return (2);
	i = 0;
	while (i < vars.philos)
	{
		philo = philos[i++];
		philo->vars = &vars;
		pthread_create(&philo->id, NULL, &philo_rotine, philo);
	}
	while (1)
	{
	}
	return (0);
}
