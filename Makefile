# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 00:21:40 by thong-bi          #+#    #+#              #
#    Updated: 2023/05/24 00:25:27 by thong-bi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = push_swap
SRCS = check_input.c\
	   do_move.c\
	   reverse.c\
	   initialize.c\
	   list_utils.c\
	   main.c\
	   push.c\
	   rotate.c\
	   sort_moves.c\
	   sort_position.c\
	   sort.c\
	   swap.c\
	   three_digit.c\
	   utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o push_swap

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
