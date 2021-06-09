# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:43:06 by ngeschwi          #+#    #+#              #
#    Updated: 2021/06/09 16:53:53 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = sources/main.c \
		sources/ft_parse_map.c \
		sources/get_next_line.c \
		sources/get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= solong

CC		= gcc
RM		= rm -f
CFLAGS	= -g3

all:		$(NAME)

%.o : %.c
	${CC} ${CFLAGS} -I./includes -o $@ -c $<

$(NAME):	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -o $(NAME)

$(OBJS):	includes/solong.h includes/get_next_line.h

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re