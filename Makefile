CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = algorithm.c check_error.c ft_split.c main.c mini_sort.c moves_functions.c push_swap.c push_swap_moves.c r_rotate.c sorting_helpers.c utils.c mini_sort_helper.c
OBJS =$(SRCS:.c=.o) 

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
