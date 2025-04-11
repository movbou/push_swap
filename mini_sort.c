#include "push_swap.h"

void	sort_3(t_list **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second > third)
	{
		swap_a(a);
		rrotate_a(a);
	}
	else if (first > second && first > third)
		rotate_a(a);
	else if (first > second)
		swap_a(a);
	else if (second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (second > third)
		rrotate_a(a);
}

void	push_smallest_to_b(t_list **a, t_list **b)
{
	int	min;
	int	pos;
	int	size;

	min = stack_min_data(*a);
	pos = stack_find_position(*a, min);
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_a(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrotate_a(a);
			pos++;
		}
	}
	push_b(a, b);
}

void	sort_4(t_list **a, t_list **b)
{
	if (!a || !*a || !b || ft_lstsize(*a) != 4)
		return ;
	push_smallest_to_b(a, b);
	sort_3(a);
	push_a(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	if (!a || !*a || !b || ft_lstsize(*a) != 5)
		return ;
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_3(a);
	push_a(a, b);
	push_a(a, b);
}

void	mini_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	if (check_list_sorted(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	else if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
