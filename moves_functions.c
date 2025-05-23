/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:15:43 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:15:48 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst, int content)
{
	t_list	*node;

	if (!lst)
	{
		return ;
	}
	node = ft_lstnew(content);
	node->content = content;
	node->next = *lst;
	*lst = node;
}

void	swap_first_2elements(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		return ;
	}
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
}

void	push_head(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node_a;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	first_node_a = *stack_a;
	*stack_a = (*stack_a)->next;
	first_node_a->next = *stack_b;
	*stack_b = first_node_a;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	first = *stack;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	rrotate(t_list **stack)
{
	t_list	*blast;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	blast = *stack;
	while (blast->next->next)
		blast = blast->next;
	last = ft_lstlast(*stack);
	blast->next = NULL;
	last->next = *stack;
	*stack = last;
}
