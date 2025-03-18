#include "push_swap.h"

void fill_chunk(int *start, int *end,t_list *stack_a)
{

}
void	sort_stack(t_list *stack_a, t_list *stack_b)
{
	int	list_length;
	int	end;


	list_length = ft_lstsize(stack_a);
	
	end = list_length / 5;
	if (list_length >= 100)
	{
		end = list_length / 16;
	}
}
