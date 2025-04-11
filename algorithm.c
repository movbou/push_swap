#include "push_swap.h"
#include <stdlib.h>


void	sort_back_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if (max_index(*stack_b) > (ft_lstsize(*stack_b) / 2))
			while (max_index(*stack_b))
				rrotate_b(stack_b);
		else
			while (max_index(*stack_b))
				rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
}

void	move_to_b(t_list **stack_a, t_list **stack_b, int end, int *tab)
{
	int	size;
	int	start;

	start = 0;
	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->content <= tab[start])
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			increment_range(&start, &end, size);
		}
		else if ((*stack_a)->content <= tab[end])
		{
			push_b(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->content < (*stack_b)->next->content)
				swap_b(stack_b);
			increment_range(&start, &end, size);
		}
		else /*if ((*stack_a)->content > tab[*end])*/
			rotate_a(stack_a);
	}
}

int	set_range(int list_length)
{
	int	chunk_size;

	chunk_size = list_length / 5;
	if (list_length == 100)
		chunk_size = list_length / 11;
	if (list_length > 100)
		chunk_size = list_length / 17;
	return (chunk_size);
}

int	*init_tab(t_list **stack_a, int numc)
{
	int	*tab;

	tab = malloc(ft_lstsize(*stack_a) * sizeof(int));
	if (!tab)
		return (NULL);
	fill_array(*stack_a, tab);
	bubble_sort(tab, numc);
	return (tab);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int numc)
{
	int	list_length;
	int	chunk_size;
	int	*tab;

	tab = init_tab(stack_a, numc);
	list_length = ft_lstsize(*stack_a);
	if (list_length <= 1)
	{
		free(tab);
		return ;
	}
	if (list_length <= 5)
	{
		mini_sort(stack_a, stack_b);
		free(tab);
		return ;
	}
	chunk_size = set_range(list_length);
	move_to_b(stack_a, stack_b, chunk_size, tab);
	sort_back_to_a(stack_a, stack_b);
	free(tab);
}
