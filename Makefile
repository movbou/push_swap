src =  algorithm.c check_error.c ft_split.c main.c mini_sort.c moves.c moves_functions.c push_swap.c sorting.c utils.c

all :
	gcc $(src) && ./a.out 3 2 1 33 4 5 44 22 555 777 0 10 10
debug:	
	gcc -ggdb $(src) && gdb ./a.out 3 2 1 33 4 5 44 22 555 777 0 10 9
