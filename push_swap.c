#include "push_swap.h"

static int	check_overflow(int m)
{
	if (m == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
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
void	s_fill(**) int main(int argc, char *argv[])
{
	t_list	stack_a;

	while (*argv[2])
	{
		push(&stack_a, )
	}
}
