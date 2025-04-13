#include "push_swap.h"

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
		return (1);
	if (handle_rotations(stack_a, stack_b, move))
		return (1);
	return (write(2, "Error\n", 6), 0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	move[4];

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!is_valid(argv, argc))
		return (1);
	s_fill(++argv, argc, &stack_a);
	while (1)
	{
		if (!read_input(move))
			break ;
		if (!do_move(&stack_a, &stack_b, move))
			return (free_stack(&stack_a), free_stack(&stack_b), 1);
	}
	if (check_list_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
