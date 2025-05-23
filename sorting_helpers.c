/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:16:20 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:16:21 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment_range(int *start, int *end, int size)
{
	if (*start < *end - 1)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}

int	*bubble_sort(int *array, int ac)
{
	int	i;
	int	j;
	int	temp;

	if (!array || ac < 2)
		return (NULL);
	j = 0;
	while (j < ac - 2)
	{
		i = 0;
		while (i < ac - 2 - j)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	return (array);
}

int	check_list_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
