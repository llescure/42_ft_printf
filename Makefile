# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llescure <llescure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 17:06:48 by llescure          #+#    #+#              #
#    Updated: 2021/02/01 22:12:56 by llescure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_buffer_allocation.c \
       ft_convert_address.c \
       ft_convert_hexa.c \
       ft_parsing.c \
       ft_parsing_part2.c \
       ft_print_cara.c \
       ft_print_int.c \
       ft_print_lower_hexa.c \
       ft_print_percent.c \
       ft_print_pointer.c \
       ft_print_string.c \
       ft_print_unsigned_int.c \
       ft_print_up_hexa.c \
       ft_printf.c \
       ft_sub_wildcard.c \
       ft_trim.c \

SUBDIR = libft

LIBRARY = libft.a

HEADER = libftprintf.h

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

all:	$(NAME)

$(NAME) : $(OBJS)
			make -C $(SUBDIR)
			cp ${SUBDIR}/${LIBRARY} ${NAME}
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

