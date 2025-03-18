src = main.c  moves.c  moves_functions.c  push_swap.c  range_sort.c  sorting.c  utils.c

all :
	gcc $(src) && ./a.out 
debug:	
	gcc -ggdb $(src) && gdb ./a.out
