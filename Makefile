# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achajar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 09:18:36 by achajar           #+#    #+#              #
#    Updated: 2025/04/13 09:18:38 by achajar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker

SRCS = algorithm.c check_error.c ft_split.c main.c mini_sort.c moves_functions.c utils2.c push_swap_moves.c r_rotate.c sorting_helpers.c utils.c mini_sort_helper.c
OBJS =$(SRCS:.c=.o) 

BONUS_SRCS = get_next_line.c get_next_line_utils.c check_error.c ft_split.c checker.c moves_functions.c utils2.c sorting_helpers.c utils.c checker_helper.c
BONUS_OBJS =$(BONUS_SRCS:.c=.o)

all:  $(NAME)
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

.PHONY: all bonus clean fclean re
.SECONDARY: $(OBJS) $(BONUS_OBJS)
