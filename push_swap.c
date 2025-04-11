#include "push_swap.h"

int	count_arg(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static long	check_overflow(int m)
{
	if (m == 1)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		m;

	i = 0;
	n = 0;
	m = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n > (LONG_MAX - (str[i] - '0')) / 10)
			return (check_overflow(m));
		n = (n * 10) + (str[i++] - 48);
	}
	return (n * m);
}

void	s_fill(char **argv, int argc, t_list **stack)
{
	argc = argc - 2;
	while (argc >= 0)
		push(stack, ft_atoi(argv[argc--]));
}

int	max_index(t_list *stack)
{
	int	i;
	int	max_index_holder;
	int	holder_of_max;

	if (!stack)
		return (-1);
	max_index_holder = 0;
	i = 0;
	holder_of_max = stack->content;
	while (stack)
	{
		if (holder_of_max < stack->content)
		{
			holder_of_max = stack->content;
			max_index_holder = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_index_holder);
}
