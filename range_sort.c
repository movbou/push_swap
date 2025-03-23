#include "push_swap.h"

void	move_to_b(int *start, int *end, t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	size;

	size = ft_lstsize(stack_a);
	while (*start < size - 1)
	{
		if (stack_a->content <= *end && stack_a->content > *start)
		{
			push_b(&stack_a, &stack_b);
			if (stack_a->next->content > stack_a->content)
				swap_b(&stack_b);
		}
		else if (stack_a->content <= *start)
		{
			push_b(&stack_a, &stack_b);
			rotate_b(&stack_b);
		}
		else if (stack_a->content >= *end)
		{
			rotate_a(&stack_a);
		}
		if (*end == size - 1)
			*start++;
		else
		{
			*start++;
			*end++;
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
