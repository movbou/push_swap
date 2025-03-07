#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
t_list	*create_the_stack(int n_element)
{
	t_list	*head;
	t_list	*node;

	head = ft_lstnew("place holder");
	node = NULL;
	while (n_element)
	{
		node = ft_lstnew("place holder");
		ft_lstadd_back(&head, node);
		node->next = NULL;
	}
	return (head);
}
