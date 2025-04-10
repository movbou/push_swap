#include "push_swap.h"
#include <unistd.h>

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

// void	rr(t_list **stack_b, t_list **stack_a)
// {
// 	rotate(stack_b);
// 	rotate(stack_a);
// 	write(1, "rr\n", 3);
// }
// void	rrr(t_list **stack_b, t_list **stack_a)
// {
// 	rrotate(stack_b);
// 	rrotate(stack_a);
// 	write(1, "rrr\n", 4);
// }

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

// void ss(t_list **stack_b, t_list **stack_a) 
// {
// 	swap_first_2elements(stack_b);
// 	swap_first_2elements(stack_a);
// 	write(1,"ss\n",3);
// }

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
