# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 16:12:23 by yohurteb          #+#    #+#              #
#    Updated: 2024/07/24 10:35:08 by yohurteb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc -g

CFLAGS = -Wall -Werror -Wextra -I include/

SRCS = \
	src/main.c \
	src/check_args.c \
	src/init.c \
	src/print.c \
	src/routine.c \
	src/threads.c \
	src/verif_stop.c \
	utils/time.c \
	utils/ft_atoi.c \
	utils/error.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
