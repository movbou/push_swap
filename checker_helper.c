/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:22:30 by achajar           #+#    #+#             */
/*   Updated: 2025/04/13 09:22:38 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	read_input(char *move)
{
	size_t	bits;
	int		i;

	i = 0;
	while (1)
	{
		bits = read(0, move + i, 1);
		if (bits <= 0)
			return (0);
		if (move[i++] == '\n')
			break ;
	}
	move[i] = 0;
	return (1);
}

int	is_valid(char **argv, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!argv[i][0])
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
