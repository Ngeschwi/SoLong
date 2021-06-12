# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:43:06 by ngeschwi          #+#    #+#              #
#    Updated: 2021/06/12 14:12:10 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = sources/main.c \
		sources/ft_parse_map.c \
		sources/ft_parse_map2.c \
		sources/ft_error.c \
		sources/gnl/get_next_line.c \
		sources/ft_strlen.c \
		sources/ft_putstr.c \
		sources/ft_strdup.c

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