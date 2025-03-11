
#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void				push(t_list **lst, int content);

t_list				*ft_lstlast(t_list *lst);

#endif
