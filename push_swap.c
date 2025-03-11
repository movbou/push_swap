#include "push_swap.h"
#include <stdio.h>

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
void	s_fill(char **argv, int argc, t_list **stack)
{
	if (!argv || !argc || !stack || !*stack)
		return ;
	/*argv++;*/
	/*push(NULL, ft_atoi(argv));*/
	while (argc--)
	{
		push(stack, ft_atoi(*(argv++)));
	}
	ft_lstlast(*stack)->next = NULL;
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
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*b[] = {"1", "2", "3"};
	char	*a[] = {"3", "2", "2"};

	/*push(&stack_a, 1);*/
	/*push(&stack_a, 2);*/
	/*push(&stack_a, 3);*/
	/*ft_lstlast(stack_a)->next=NULL;*/
	s_fill(b, 3, &stack_b);
	s_fill(b, 3, &stack_a);
	/*s_fill(*argv, argc, &stack_a);*/
	print_stack(stack_b);
	print_stack(stack_a);
}
