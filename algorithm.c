#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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

void	increment_range(int *start, int *end, int size)
{
	if (*start < *end)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}

void	move_to_b(t_list **stack_a, t_list **stack_b, int end, int *tab)
{
	int	size;
	int	start;

	start = 0;
	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->content <= tab[start])
		{
			push_b(stack_a, stack_b);
			printf("\n");
			rotate_b(stack_b);
			printf("\n");
			increment_range(&start, &end, size);
		}
		else if ((*stack_a)->content <= tab[end])
		{
			push_b(stack_a, stack_b);
			printf("\n");
			if (*stack_b && (*stack_b)->next &&
				(*stack_b)->content < (*stack_b)->next->content)
				swap_b(stack_b);
			printf("\n");
			increment_range(&start, &end, size);
		}
		else /*if ((*stack_a)->content > tab[*end])*/
			rotate_a(stack_a);
	}
}

void	fill_array(t_list *stack_a, int *tab)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		tab[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b, int numc)
{
	int	list_length;
	int	chunk_size;
	int	*tab;


	tab = malloc(ft_lstsize(*stack_a));
	fill_array(*stack_a, tab);
	bubble_sort(tab, numc);
	list_length = ft_lstsize(*stack_a);
	if (list_length <= 1)
		return ;
	if (list_length <= 5)
	{
		mini_sort(stack_a, stack_b);
		return ;
	}
	chunk_size = list_length / 5;
	if (list_length >= 100)
		chunk_size = list_length / 16;
	move_to_b(stack_a, stack_b, chunk_size, tab);
	sort_back_to_a(stack_a, stack_b);
	free(tab);
	free_stack(stack_a);
}
