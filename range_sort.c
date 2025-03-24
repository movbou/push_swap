#include "push_swap.h"

int	max_index(t_list *stack)
{
	int	i;
	int	max_index_holder;
	int	holder_of_max;

	if (!stack)
		return (-1);
	// mamakdch saraha mn had lblan imkn hsn anani ninisializiha b -1 o safi
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

void	sort_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	half_size_b;
	int	max_idx;
	int	i;

	while (*stack_b)
	{
		half_size_b = ft_lstsize(*stack_b) / 2;
		max_idx = max_index(*stack_b);
		if (max_idx <= half_size_b)
		{
			i = max_idx;
			while (i--)
				rotate_b(stack_b);
		}
		else
		{
			i = ft_lstsize(*stack_b) - max_idx;
			while (i--)
				rrotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void	move_to_b(t_list **stack_a, t_list **stack_b, int *start, int *end)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (*start < size && ft_lstsize(*stack_a) > 0)
	{
		if ((*stack_a)->content <= *end && (*stack_a)->content > *start)
		{
			push_b(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next &&
				(*stack_b)->content < (*stack_b)->next->content)
				swap_b(stack_b);
		}
		else if ((*stack_a)->content <= *start)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else if ((*stack_a)->content > *end)
		{
			rotate_a(stack_a);
		}
		if (ft_lstsize(*stack_a) == 0 || *stack_a == NULL)
			break ;
		if (*end == size - 1)
			(*start)++;
		else
		{
			(*start)++;
			(*end)++;
		}
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	list_length;
	int	chunk_size;
	int	start;
	int	end;

	if (!stack_a || !*stack_a)
		return ;
	list_length = ft_lstsize(*stack_a);
	if (list_length <= 1)
		return ;
	if (list_length <= 5)
	{
		return ;
	}
	chunk_size = list_length / 5;
	if (list_length >= 100)
		chunk_size = list_length / 16;
	start = 0;
	end = chunk_size;
	while (ft_lstsize(*stack_a) > 0)
	{
		move_to_b(stack_a, stack_b, &start, &end);
		if (end < list_length - 1)
		{
			start = end + 1;
			end = start + chunk_size;
			if (end > list_length - 1)
				end = list_length - 1;
		}
	}
	sort_back_to_a(stack_a, stack_b);
}
