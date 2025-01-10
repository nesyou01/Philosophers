#include "philo_bonus.h"

static void	philo_rotine(t_philo *philo)
{
	sleep(2);
	printf("THIS IS A PHILO %d\n", philo->nbr);
	exit(0);
}

int	ft_philo(t_vars vars)
{
	t_philo	**philos;
	int		i;
    pid_t	pid;

	philos = ft_philos_init(vars);
	if (!philos)
		return (free_until(NULL, 0, &vars), 2);
	i = 0;
	while (i < vars.philos)
	{
		pid = fork();
		if (pid == 0)
			philo_rotine(philos[i]);
		else
			philos[i]->id = pid;
		i++;
	}
	i = 0;
	while (i < vars.philos)
		waitpid(philos[i++]->id, NULL, 0);
	return (0);
}
