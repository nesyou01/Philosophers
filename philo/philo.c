#include "philo.h"

static void	free_until(t_philo **philos, int until)
{
	int		i;

	i = 0;
	while (i < until)
		free(philos[i++]);
	free(philos);
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
	i = 0;
	while (i < vars.philos)
	{
		if (i == vars.philos - 1)
			result[i]->r_fork = &result[0]->fork;
		else
			result[i]->r_fork = &result[i + 1]->fork;
		i++;
	}
	return (result);
}

int	ft_philo(t_vars vars)
{
	t_philo	**philos;

	philos = ft_philos_init(vars);
	if (!philos)
		return (2);
	

	return (0);
}
