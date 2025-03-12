#include "push_swap.h"

int	*bubble_sort(int *array, int ac)
{
	int	i;
	int	j;
	int	temp;

	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ac)
	{
		while (i < ac)
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
