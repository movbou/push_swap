/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:23:52 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:23:56 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	should_reverse_stack(t_list *stack)
{
	t_list	*current;
	int		count;
	int		total_comparisons;
	int		stack_size;

	if (!stack || !stack->next)
		return (0);
	count = 0;
	current = stack;
	stack_size = ft_lstsize(stack);
	total_comparisons = stack_size - 1;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			count++;
		current = current->next;
	}
	return (count > (total_comparisons * 75) / 100);
}

void	check_and_reverse_if_needed(t_list **stack_a, t_list **stack_b)
{
	if (should_reverse_stack(*stack_a))
	{
		while (*stack_a)
			push_b(stack_a, stack_b);
		while (*stack_b)
		{
			rrotate_b(stack_b);
			push_a(stack_a, stack_b);
		}
	}
}

char	**string_handle(int *argc, char **argv, int *f)
{
	char	**holder;

	*argc = word_count(argv[1], ' ') + 1;
	holder = ft_split(argv[1], ' ');
	if (!holder)
		exit_here(holder, *argc);
	*f = 1;
	return (holder);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**holder;
	int		f;

	if (argc < 2)
		return (0);
	f = 0;
	stack_a = NULL;
	stack_b = NULL;
	check_error(argc, argv);
	holder = argv + 1;
	if (argc == 2)
		holder = string_handle(&argc, argv, &f);
	s_fill(holder, argc, &stack_a);
	sort_stack(&stack_a, &stack_b, argc);
	free_stack(&stack_a);
	if (f)
		free_array(holder);
	return (0);
}
