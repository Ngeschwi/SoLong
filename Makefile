# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:43:06 by ngeschwi          #+#    #+#              #
#    Updated: 2021/06/28 12:34:44 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = sources/main.c \
		sources/parse/ft_parse_map.c \
		sources/parse/ft_parse_map2.c \
		sources/error_free/ft_error.c \
		sources/error_free/ft_free_map.c \
		sources/gnl/get_next_line.c \
		sources/basic_function/ft_strlen.c \
		sources/basic_function/ft_putstr.c \
		sources/basic_function/ft_strdup.c

OBJS	= $(SRCS:.c=.o)

NAME	= solong

CC		= gcc
RM		= rm -f
CFLAGS	= -g

all:		$(NAME)

%.o : %.c
	${CC} ${CFLAGS} -I./includes -I./minilibX -o $@ -c $<

$(NAME):	$(OBJS)
		${CC} ${CFLAGS}  $(OBJS) -o $(NAME)

$(OBJS):	includes/solong.h includes/get_next_line.h

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re