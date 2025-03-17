#include "push_swap.h"

int	*bubble_sort(int *array, int ac)
{
	int	i;
	int	j;
	int	temp;

	if (!array || ac < 2)
		return (NULL);
	j = 0;
	while (j < ac - 1)
	{
		i = 0;
		while (i < ac - 1 - j)
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

void	min_max(int *sorted_array, int *min, int *max, int ac)
{
	*min = sorted_array[0];
	*max = sorted_array[ac];
}

int	in_range(int min_range, int max_range, int content)
{
	return (content <= max_range && content >= min_range);
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

