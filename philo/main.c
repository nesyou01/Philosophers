#include "philo.h"

static void	*philo_lifecycle(void *attrs)
{
	t_philo	*philo;

	philo = (t_philo *) attrs;
	
	while (1)
	{
		printf("%d ttttt\n", philo->nbr);
		usleep(1000 * 1000);
	}
	return (NULL);
}

static void	*monitor(void *attrs)
{
	t_philo	**philos;

	philos = (t_philo **) attrs;
	
	while (1)
	{
	}
	return (NULL);
}

static void	philo_start(t_vars vars)
{
	pthread_t	monitor_id;
	t_philo		**philos;
	t_philo		*philo;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philo) * vars.number_of_philosopher); // Protection
	while (i < vars.number_of_philosopher)
	{
		philo = malloc(sizeof(t_philo));
		philo->nbr = i + 1;
		philos[i] = philo;
		pthread_create(&philo->id, NULL, philo_lifecycle, philo);
		i++;
	}
	pthread_create(&monitor_id, NULL, monitor, philos);
	pthread_join(monitor_id, NULL);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 5 || argc > 6 || ft_prase_vars(argc, argv, &vars))
		return (1);
	philo_start(vars);	
	return (0);
}
