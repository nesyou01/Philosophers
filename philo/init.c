#include "philo.h"

static int	init_forks(t_philo **philos, t_vars vars)
{
	int		i;

	i = 0;
	while (i < vars.philos)
	{
		if (pthread_mutex_init(&philos[i]->fork, NULL) != 0)
			return (1);
		if (i == vars.philos - 1)
			philos[i]->r_fork = &philos[0]->fork;
		else
			philos[i]->r_fork = &philos[i + 1]->fork;
		i++;
	}
	return (0);
}

t_philo	**ft_philos_init(t_vars vars)
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
			return (free_until(result, i, &vars), NULL);
		philo->eat_times = 0;
		philo->nbr = i + 1;
		result[i++] = philo;
	}
	if (init_forks(result, vars))
		return (free_until(result, vars.philos, &vars), NULL);
	return (result);
}
