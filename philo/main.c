#include "philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 5 || argc > 6 || ft_prase_vars(argc, argv, &vars))
		return (1);
	if (pthread_mutex_init(&vars.m_stop, NULL) != 0)
		return (3);
	if (pthread_mutex_init(&vars.m_print, NULL) != 0)
		return (3);
	vars.stop = 0;
	return (ft_philo(vars));
}
