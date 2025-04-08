src =  algorithm.c check_error.c ft_split.c main.c mini_sort.c moves.c moves_functions.c push_swap.c sorting.c utils.c

all :
	gcc -g $(src) -o push_swap
fclean :
	rm -f push_swap
