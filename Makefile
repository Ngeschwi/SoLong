# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:43:06 by ngeschwi          #+#    #+#              #
#    Updated: 2021/07/01 16:00:48 by ngeschwi         ###   ########.fr        #
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
LIBS	= -Lmlx -lmx -framework OpenGL -framework AppKit -lm
MLX		= libmlx.dylib

all:		$(NAME)

%.o : %.c
	${CC} ${CFLAGS} -I./includes -I./mlx -c $< -o $@

$(NAME):	${MLX} $(OBJS)
		${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

$(MLX) :
		$(MAKE) -C mlx
		@mv mlx/$(MLX)	.

$(OBJS):	includes/solong.h includes/get_next_line.h

clean:
		$(MAKE) -C mlx clean
		$(RM) libmlx.dylib
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re