#include "push_swap.h"

void	fill_a_part(int *start, int *end, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = end - start + 2;
	while (i--)
	{
		if (peek(stack_a) >= *end)
		{
			rotate_a(&stack_a);
		}
		else
		{
			push_b(&stack_a, &stack_b);
			rotate_b(&stack_b);
		}
	}
}
void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	int	list_length;
	int	end;

	list_length = ft_lstsize(stack_a);
	end = list_length / 5;
	if (list_length >= 100)
		end = list_length / 16;
}
