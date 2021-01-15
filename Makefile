# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llescure <llescure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 17:06:48 by llescure          #+#    #+#              #
#    Updated: 2021/01/15 16:37:10 by llescure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = main.c

SUBDIR = libft

HEADER = printf.h

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

all:	$(NAME)

$(NAME) : $(OBJS)
			make -C $(SUBDIR)
			ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
			$(CC) -c $(CFLAGS) $< -o $@

clean: 
		make fclean -C $(SUBDIR)
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

