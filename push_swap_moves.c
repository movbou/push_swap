#include "push_swap.h"
#include <unistd.h>

void swap_a(t_list **stack_a) 
{
	swap_first_2elements(stack_a);
	write(1,"sa\n",3);
}

void swap_b(t_list **stack_b) 
{
	swap_first_2elements(stack_b);
	write(1,"sb\n",3);
}


void	push_a(t_list **stack_a, t_list **stack_b)
{
	push_head(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push_head(stack_a, stack_b);
	write(1, "pb\n", 3);
}
