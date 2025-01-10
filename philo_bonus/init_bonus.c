#include "philo_bonus.h"

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
	return (result);
}

int	ft_prase_vars(int argc, char **argv, t_vars *vars)
{
	int	error;

	error = 0;
	vars->philos = ft_atoi(argv[1], &error);
	vars->time_to_die = ft_atoi(argv[2], &error);
	vars->time_to_eat = ft_atoi(argv[3], &error);
	vars->time_to_sleep = ft_atoi(argv[4], &error);
	vars->max_eat = -1;
	if (argc == 6)
		vars->max_eat = ft_atoi(argv[5], &error);
	return (error);
}
