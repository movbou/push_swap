
#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				*data;
	struct s_list	*next;
}					t_list;

#endif
