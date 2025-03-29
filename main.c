#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	int end =2;
	int		tab[]= {0,1,2,3,4,5,6,7,8,9};
	int		i=0;

	stack_a = NULL;
	stack_b = NULL;
	s_fill(++argv, argc-1, &stack_a);
	printf("stacka:\n");
	print_stack(stack_a);
	printf("stackb:\n");
	print_stack(stack_b);

move_to_b( &stack_a, &stack_b, end, tab);
	
	printf("\nstacka:\n");
	print_stack(stack_a);
	printf("stackb:\n");
	print_stack(stack_b);
	


}

/*t_list	*stack_a;*/
/*t_list	*stack_b;*/
/**/
/*stack_a = NULL;*/
/*stack_b = NULL;*/
/*if (argc < 2)*/
/*	return (0);*/
/*if (!parse_arguments(argc, argv, &stack_a))*/
/*{*/
/*	write("error\n", 6);*/
/*	free_stack(&stack_a);*/
/*	return (1);*/
/*}*/
/*sort_stack(&stack_a, &stack_b, argc);*/
/*print_stack(stack_a);*/
/*free_stack(&stack_a);*/
/*free_stack(&stack_b);*/
/*return (0);*/
