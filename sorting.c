#include "push_swap.h"

int	*bubble_sort(int *array, int ac)
{
	int	i;
	int	j;
	int	temp;

	if (!array || ac < 2)
		return (NULL);
	j = 0;
	while (j < ac - 2)
	{
		i = 0;
		while (i < ac - 2 - j)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	return (array);
}

int	check_list_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
