#include "push_swap.h"
#include <stdlib.h>


void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(lst);
		*lst = temp;
	}
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

void	push(t_list **lst, int content)
{
	t_list	*node;

	if (!lst)
	{
		return ;
	}
	node = ft_lstnew(content);
	node->content = content;
	node->next = *lst;
	*lst = node;
}

void	swap_first_2elements(t_list **stack)
{
	t_list	*temp;

	if (!stack)
	{
		return ;
	}
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
}

void	swap_heads(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*pswap;

	if (!stack_a || !stack_b)
		return ;
	pswap = temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	pswap = *stack_a;
	*stack_a = *stack_b;
	*stack_b = pswap;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	first = *stack;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	rrotate(t_list **stack)
{
	t_list	*blast;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	blast = *stack;
	while (blast->next->next)
		blast = blast->next;
	last = ft_lstlast(*stack);
	blast->next = NULL;
	last->next = *stack;
	*stack = last;
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
 
