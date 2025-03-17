#include "push_swap.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list	*stack_a = NULL;
	t_list	*stack_b= NULL;
	t_list	*stack_c= NULL;
	t_list	*stack_d= NULL;
	char	*a[] = {"1", "2", "3", "4"};
	char	*b[] = {"1", "4", "3","4","5","3"};
	char	*c[] = {"2", "4", "3","4"};
	char	*d[] = {"1", "0", "3","4","5"};

	printf("stack_a\n");
	s_fill(a, 4, &stack_a);
	print_stack(stack_a);

	printf("stack_b\n");
	s_fill(b, 6, &stack_b);
	print_stack(stack_b);
	printf("stack_c\n");
	s_fill(c, 4, &stack_c);
	print_stack(stack_c);
	printf("stack_d\n");
	s_fill(d, 5, &stack_d);
	print_stack(stack_d);



}
