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

void	initialize_data(t_list **stack_a, t_list **stack_b, int *f_flag)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*f_flag = 0;
}

char	**parse_and_validate_args(int *argc, char **argv, int *f_flag)
{
	char	**holder;

	if (*argc == 1)
		exit(0);
	check_error(*argc, argv);
	holder = argv + 1;
	if (*argc == 2)
	{
		holder = string_handle(argc, argv, f_flag);
	}
	if (!is_valid(holder, *argc))
	{
		if (*f_flag)
			free_array(holder);
		exit(1);
	}
	return (holder);
}

int	is_valid(char **argv, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
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
