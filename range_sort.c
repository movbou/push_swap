#include "push_swap.h"

int	max_index(t_list *stack)
{
	int	i;
	int	max_index_holder;
	int	holder_of_max;

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

void	sort_back_to_a(t_list *stack_a, t_list *stack_b)
{
	int	half_size_b;
	int	max_index;
	int	i;

	half_size_b = ft_lstsize(stack_b) / 2;
	while (stack_b)
	{
		max_index = max_index(stack_b);
		if (max_index < half_size_b)
		{
			i = max_index;
			while (i--)
				rotate_b(&stack_b);
		}
		if (max_index >= half_size_b)
		{
			i = max_index - ft_lstsize(stack_b);
			while (i--)
				rrotate_b(&stack_b);
		}
	
	}
}

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

void push_bak_to_a void sort_stack(t_list *stack_a, t_list *stack_b)
{
	int	list_length;
	int	end;

	list_length = ft_lstsize(stack_a);
	end = list_length / 5;
	if (list_length >= 100)
		end = list_length / 16;
}
