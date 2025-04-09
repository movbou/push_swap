#include "push_swap.h"

int	stack_min_data(t_list *copy)
{
	int	min;

	min = copy->content;
	while (copy->next != NULL)
	{
		if (copy->next->content < min)
			min = copy->next->content;
		copy = copy->next;
	}
	return (min);
}

int	stack_max_data(t_list *copy)
{
	int	max;

	max = copy->content;
	while (copy->next != NULL)
	{
		if (copy->next->content > max)
			max = copy->next->content;
		copy = copy->next;
	}
	return (max);
}

int	stack_min_position(t_list *stack, int min)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		if (min == stack->content)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	sort_3(t_list **a)
{
	if (stack_min_data(*a) == (*a)->content)
	{
		swap_a(&(*a));
		rotate_a(&(*a));
	}
	else if (stack_max_data(*a) == (*a)->content)
	{
		rotate_a(&(*a));
		if (check_list_sorted(*a) == 1)
			swap_a(&(*a));
	}
	else if (stack_min_data(*a) == (*a)->next->content)
		swap_a(&(*a));
	else if (stack_max_data(*a) == (*a)->next->content)
		rrotate_a(a);
}

// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 2 1 
// 3 1 2 



void	stack_push_min(int i, t_list **a, t_list **b)
{
	if (i == 0)
		push_b((&(*a)), (&(*b)));
	else if (i == 1)
	{
		swap_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
	else if (i == 2)
	{
		rotate_a(&(*a));
		rotate_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
	else if (i == 3)
	{
		rrotate_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
}

void	stack_push_5min(int i, t_list **a, t_list **b)
{
	if (i == 0)
		push_b((&(*a)), (&(*b)));
	else if (i == 1)
	{
		swap_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
	else if (i == 2)
	{
		rotate_a(&(*a));
		rotate_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
	else if (i == 3)
	{
		rrotate_a(&(*a));
		rrotate_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
	else if (i == 4)
	{
		rrotate_a(&(*a));
		push_b((&(*a)), (&(*b)));
	}
}

void	sort_4(t_list **a, t_list **b)
{
	int	index;

	index = stack_min_position((*a), stack_min_data(*a));
	stack_push_min(index, &(*a), &(*b));
	if (check_list_sorted(*a) == 0)
		push_a(&(*a), &(*b));
	else
	{
		sort_3(&(*a));
		push_a(&(*a), &(*b));
	}
}

void	sort_5(t_list **a, t_list **b)
{
	int	index;

	index = stack_min_position((*a), stack_min_data(*a));
	stack_push_5min(index, &(*a), &(*b));
	if (check_list_sorted(*a) == 0)
		push_a(&(*a), &(*b));
	else
	{
		sort_4((&(*a)), (&(*b)));
		push_a(&(*a), &(*b));
	}
}

void	mini_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (check_list_sorted(*stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
