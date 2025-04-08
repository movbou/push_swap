#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  t_list *stack_a;
  t_list *stack_b;
  char **holder;
  int f = 0;

  stack_a = NULL;
  stack_b = NULL;
  if (argc < 2)
    return (0);

  holder = argv + 1;
  if (argc == 2) {
    holder = ft_split(argv[1], ' ');
    argc = word_count(argv[1], ' ') + 1;
    f = 1;
  }
  check_error(argc, holder);
  s_fill(holder, argc, &stack_a);
  sort_stack(&stack_a, &stack_b, argc);
  print_stack(stack_a);
  free_stack(&stack_a);
  free_stack(&stack_b);
  if (f)
    free_array(holder);
  return (0);
}

/*t_list	*stack_a;*/
/*t_list	*stack_b;*/
/**/
/*int end =2;*/
/*int		tab[]= {0,1,2,3,4,5,6,7,8,9};*/
/*int		i=0;*/
/**/
/*stack_a = NULL;*/
/*stack_b = NULL;*/
/*s_fill(++argv, argc-1, &stack_a);*/
/**/
/*move_to_b( &stack_a, &stack_b, end, tab);*/
/**/
/*printf("stack_a:\n");*/
/*print_stack(stack_a);*/
/*printf("stack_b:\n");*/
/*print_stack(stack_b);*/
/**/
/*sort_back_to_a(&stack_a, &stack_b);*/
/**/
/**/
/*printf("\nstack_a:\n");*/
/*print_stack(stack_a);*/
/*printf("stack_b:\n");*/
/*print_stack(stack_b);*/
