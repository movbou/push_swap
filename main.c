#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	/*if (!parse_arguments(argc, argv, &stack_a))*/
	/*{*/
	/*	write("error\n", 6);*/
	/*	free_stack(&stack_a);*/
	/*	return (1);*/
	/*}*/
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
