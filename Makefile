CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker

SRCS = algorithm.c check_error.c ft_split.c main.c mini_sort.c moves_functions.c utils2.c push_swap_moves.c r_rotate.c sorting_helpers.c utils.c mini_sort_helper.c
OBJS =$(SRCS:.c=.o) 

BONUS_SRCS = check_error.c ft_split.c checker.c moves_functions.c utils2.c sorting_helpers.c utils.c checker_helper.c
BONUS_OBJS =$(BONUS_SRCS:.c=.o)

all:  $(NAME) $(BONUS)
bonus: $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(NAME) $(BONUS)
re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(BONUS_OBJS)
