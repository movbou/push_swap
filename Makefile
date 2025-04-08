src =  algorithm.c check_error.c ft_split.c main.c mini_sort.c moves.c moves_functions.c push_swap.c sorting.c utils.c

all :
	gcc $(src) -o push_swap
# debug:	
# 	gcc -ggdb $(src)
