#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 5 || argc > 6 || ft_prase_vars(argc, argv, &vars))
		return (1);
	vars.stop = 0;
	return (ft_philo(vars));
}