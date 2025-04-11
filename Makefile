src = algorithm.c check_error.c ft_split.c main.c mini_sort.c moves_functions.c push_swap.c push_swap_moves.c r_rotate.c sorting_helpers.c utils.c mini_sort_helper.c
all :
	gcc -ggdb $(src) -o push_swap
fclean :
	rm -f push_swap
