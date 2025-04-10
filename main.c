#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**holder;
	int		f;

	f = 0;
	stack_a = NULL;
	stack_b = NULL;
	check_error(argc, argv);
	if (argc < 2)
		return (0);
	holder = argv + 1;
	if (argc == 2)
	{
		holder = ft_split(argv[1], ' ');
		argc = word_count(argv[1], ' ') + 1;
		f = 1;
	}
	s_fill(holder, argc, &stack_a);
	sort_stack(&stack_a, &stack_b, argc);
	/*print_stack(stack_a);*/
	free_stack(&stack_a);
	if (f)
		free_array(holder);
	return (0);
}
