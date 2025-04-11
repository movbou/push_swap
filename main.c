#include "push_swap.h"
#include <stdio.h>
 
char	**string_handle(int *argc, char **argv, int *f)
{
	char	**holder;

	holder = ft_split(argv[1], ' ');
	*argc = word_count(argv[1], ' ') + 1;
	*f = 1;
	return (holder);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**holder;
	int		f;

	f = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_error(argc, argv);
	holder = argv + 1;
	if (argc == 2)
		holder = string_handle(&argc, argv, &f);
	s_fill(holder, argc, &stack_a);
	sort_stack(&stack_a, &stack_b, argc);
	free_stack(&stack_a);
	if (f)
		free_array(holder);
	return (0);
}
