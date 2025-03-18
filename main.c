#include "push_swap.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list	*stack_a = NULL;
	t_list	*stack_b= NULL;
	t_list	*stack_c= NULL;
	t_list	*stack_d= NULL;
	char	*a[] = {"1", "2", "3", "4"};
	char	*b[] = {"5", "4", "3","2","1","0"};


	printf("stack_a\n");
	s_fill(a, 4, &stack_a);
	print_stack(stack_a);

	printf("\n");
	
	printf("stack_b:\n");
	s_fill(b, 6, &stack_b);
	print_stack(stack_b);

	push_a(&stack_a, &stack_b);/*-----------------------------------------------------------------------------------------*/
	printf(".............................................\n");

	printf("stack_a\n");
	print_stack(stack_a);

	printf("\n");
	
	printf("stack_b:\n");
	print_stack(stack_b);
}
