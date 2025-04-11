#include "push_swap.h"
#include <limits.h>

int	check_doubles(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nbr(char *argv)
{
	int	i;

	i = 0;
	if (!argv || !argv[0])
		return (0);
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!(argv[i] <= '9' && argv[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char	**init_check_error(int argc, char **argv)
{
	char	**tmp_array;

	if (argc == 2)
		tmp_array = ft_split(argv[1], ' ');
	else
		tmp_array = argv + 1;
	if (!tmp_array || !tmp_array[0])
	{
		free_array(tmp_array);
		exit_error();
	}
	return (tmp_array);
}

void	check_error(int argc, char **argv)
{
	int		i;
	long	tmp_argv;
	char	**tmp_array;

	i = 0;
	tmp_array = init_check_error(argc, argv);
	while (tmp_array[i])
	{
		tmp_argv = ft_atoi(tmp_array[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
			exit_error();
		if (!check_nbr(tmp_array[i]))
			exit_error();
		if (check_doubles(tmp_array))
			exit_error();
		i++;
	}
	if (argc == 2)
		free_array(tmp_array);
}
