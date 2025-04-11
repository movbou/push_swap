#include "push_swap.h"
#include <stdlib.h>

void	fill_array(t_list *stack_a, int *tab)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		tab[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}


int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
