#include "philo_bonus.h"

static void	philo_rotine(t_philo *philo, t_vars vars)
{
	if (philo->nbr % 2 == 0)
		ft_usleep(vars.time_to_sleep / 5, philo, vars);
	while (1)
	{
		if (ft_eat(philo, vars))
			break ;
		ft_sleep(philo, vars);
		ft_think(philo, vars);
		if (philo->eat_times != -1 && philo->eat_times >= vars.max_eat)
			break ;
	}
	exit(0);
}

static int	init_processes(t_philo **philos, t_vars vars)
{
	int		i;
    pid_t	pid;

	i = 0;
	while (i < vars.philos)
	{
		pid = fork();

		if (pid < 0)
			return (1);
		else if (pid == 0)
			philo_rotine(philos[i], vars);
		else
			philos[i]->id = pid;
		i++;
	}
	i = 0;
	while (i < vars.philos)
		waitpid(philos[i++]->id, NULL, 0);
	return (0);
}

static void	unlink_sems()
{
	sem_unlink("/forks");
	sem_unlink("/print");
}

int	ft_philo(t_vars vars)
{
	t_philo	**philos;
	int		code;

	philos = ft_philos_init(vars);
	if (!philos)
		return (free_until(NULL, 0, &vars), 2);
	unlink_sems();
	vars.forks_sem = sem_open("/forks", O_CREAT, 0664, vars.philos);
	vars.print_sem = sem_open("/print", O_CREAT, 0664, 1);
	if (vars.forks_sem == SEM_FAILED)
		code = 5;
	else
	{
		vars.started_at = ft_current_time();
		code = init_processes(philos, vars);
    	sem_close(vars.forks_sem);
		unlink_sems();
	}
	return (free_until(NULL, 0, &vars), code);
}
