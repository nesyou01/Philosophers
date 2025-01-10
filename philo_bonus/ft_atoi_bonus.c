# include "philo_bonus.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_atoi(char *str, int *error)
{
	size_t	result;
	int		i;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		if (result * 10 >= ULONG_MAX - 5 && (str[i] - '0') > 5)
			return (*error = 1, 0);
		result = result * 10 + (str[i++] - '0');
	}
	if (str[i])
		*error = 1;
	return (result);
}
