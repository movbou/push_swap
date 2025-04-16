/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:14:24 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:14:26 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	handle_swap_and_push(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		swap_first_2elements(stack_a);
	else if (!ft_strcmp(move, "sb\n"))
		swap_first_2elements(stack_b);
	else if (!ft_strcmp(move, "ss\n"))
	{
		swap_first_2elements(stack_b);
		swap_first_2elements(stack_a);
	}
	else if (!ft_strcmp(move, "pa\n"))
		push_head(stack_b, stack_a);
	else if (!ft_strcmp(move, "pb\n"))
		push_head(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	handle_rotations(t_list **stack_a, t_list **stack_b, char *move)
{
	if (!ft_strcmp(move, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(move, "rr\n"))
	{
		rotate(stack_b);
		rotate(stack_a);
	}
	else if (!ft_strcmp(move, "rra\n"))
		rrotate(stack_a);
	else if (!ft_strcmp(move, "rrb\n"))
		rrotate(stack_b);
	else if (!ft_strcmp(move, "rrr\n"))
	{
		rrotate(stack_b);
		rrotate(stack_a);
	}
	else
		return (0);
	return (1);
}

int	do_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (handle_swap_and_push(stack_a, stack_b, move))
		return (0);
	if (handle_rotations(stack_a, stack_b, move))
		return (0);
	return (1);
}

int	operation_checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (do_move(a, b, line))
		{
			free_stack(a);
			free_stack(b);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		f;
	char	**holder;

	f = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	check_error(argc, argv);
	holder = argv + 1;
	if (argc == 2)
		holder = string_handle(&argc, argv, &f);
	if (!is_valid(holder, argc))
		return (1);
	s_fill(holder, argc, &stack_a);
	if (!operation_checker(&stack_a, &stack_b))
		exit_here(holder, argc);
	else
	{
		if (check_list_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	if (f)
		free_array(holder);
	return (free_stack(&stack_b), free_stack(&stack_a), 0);
}
