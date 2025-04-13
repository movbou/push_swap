/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:15:34 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:15:37 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_min_data(t_list *copy)
{
	int		min;
	t_list	*current;

	if (!copy)
		return (0);
	min = copy->content;
	current = copy;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int	stack_max_data(t_list *copy)
{
	int		max;
	t_list	*current;

	if (!copy)
		return (0);
	max = copy->content;
	current = copy;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	stack_find_position(t_list *stack, int value)
{
	int	pos;

	if (!stack)
		return (-1);
	pos = 0;
	while (stack)
	{
		if (stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
