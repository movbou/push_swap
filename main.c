#include "push_swap.h"
int	main(int argc, char *argv[])
{
	t_list	*stack_a = NULL;
	t_list	*stack_b= NULL;
	char	*b[] = {"3", "3", "3", "4"};
	char	*a[] = {"1", "1", "1"};

	s_fill(b, 4, &stack_b);
	s_fill(a, 3, &stack_a); 

	printf("stack_b\n");
	print_stack(stack_b);
	/*printf("stack_a\n");*/
	/*print_stack(stack_a);*/

	printf("***\n");
	swap_first_2elements(&stack_b)	;
	printf("stack_b\n");
	print_stack(stack_b);
	/*printf("stack_a\n");*/
	/*print_stack(stack_a);*/
}
