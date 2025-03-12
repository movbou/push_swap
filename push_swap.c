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
	if (!argv || !argc)
		return ;
	/*argv++;*/
	/*push(NULL, ft_atoi(argv));*/
	while (argc--)
	{
		push(stack, ft_atoi(*(argv++)));
	}
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
	t_list	*stack_a = NULL;
	t_list	*stack_b= NULL;
	char	*b[] = {"3", "3", "3", "4"};
	char	*a[] = {"1", "1", "1"};

	s_fill(b, 4, &stack_b);
	s_fill(a, 3, &stack_a); 

	printf("stack_b\n");
	print_stack(stack_b);
	/*printf("stack_a\n");*/
	/*print_stack(stack_a);*/

	printf("***\n");
	swap_first_2elements(&stack_b)	;
	printf("stack_b\n");
	print_stack(stack_b);
	/*printf("stack_a\n");*/
	/*print_stack(stack_a);*/
}
