#include "push_swap.h"

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
	if (!lst || !content) {
		return;
	}
	t_list	*node;

	node = ft_lstnew(content);
	node->content= content;
	node->next = *lst;
	*lst = node;
}

void swap_first_2elements(t_list *stack)
{

}
void swap_heads(t_list stack_a,t_list stack_b)
{

}

void rotate(t_list *stack)
{

}
