#include "push_swap.h"
#include <stdio.h>

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
		n = (n * 10) + (str[i++] - 48);
	}
	return (n * m);
}
void	s_fill(char **argv, int argc, t_list **stack)
{
	char **holder;
	int f = 0;
	if (argc == 2){
		holder = ft_split(argv[1], ' ');
		argc = word_count(argv[1], ' ')+1;
		f=1;
	}
	else
	 holder = argv + 1;
	argc=argc-2;
	while (argc >= 0)
		push(stack, ft_atoi(holder[argc--]));
	if (f)
		free_array(holder);
	
}

void	print_stack(t_list *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}


