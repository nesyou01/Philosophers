# include "philo.h"

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
