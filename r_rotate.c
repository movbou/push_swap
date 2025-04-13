/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:16:10 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:16:12 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rrotate_a(t_list **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_list **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}
