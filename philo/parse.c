# include "philo.h"

int	ft_prase_vars(int argc, char **argv, t_vars *vars)
{
	int	error;

	error = 0;
	printf("%lu -- %d", ft_atoi(argv[1], &error), error);
	return (error);
}
