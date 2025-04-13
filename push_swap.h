
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

void				check_and_reverse_if_needed(t_list **stack_a,
						t_list **stack_b);
int					ft_strcmp(char *s1, char *s2);
int					read_input(char *move);
int					is_valid(char **argv, int ac);
int					stack_find_position(t_list *stack, int value);
int					stack_min_data(t_list *copy);
int					count_arg(char **array);
char				**free_array(char **s);
void				increment_range(int *start, int *end, int size);
int					word_count(const char *str, char c);
char				**free_array(char **s);
void				mini_sort(t_list **stack_a, t_list **stack_b);
void				check_error(int argc, char **argv);
char				**ft_split(const char *s, char c);
void				fill_array(t_list *stack_a, int *tab);
int					*bubble_sort(int *array, int ac);
void				free_stack(t_list **stack);
int					max_index(t_list *stack);
void				sort_back_to_a(t_list **stack_a, t_list **stack_b);
void				move_to_b(t_list **stack_a, t_list **stack_b, int end,
						int *tab);
void				sort_stack(t_list **stack_a, t_list **stack_b, int numc);
void				rotate_b(t_list **stack_b);
void				rrotate_a(t_list **stack_a);
void				rrotate_b(t_list **stack_b);
void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
int					ft_lstsize(t_list *lst);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push(t_list **lst, int content);
long				ft_atoi(const char *str);
int					check_list_sorted(t_list *stack);
void				s_fill(char **argv, int argc, t_list **stack);
void				swap_first_2elements(t_list **stack);
void				push_head(t_list **stack_a, t_list **stack_b);
void				rrotate(t_list **stack);
void				rotate(t_list **stack);
t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);

#endif
