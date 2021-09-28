# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:43:06 by ngeschwi          #+#    #+#              #
#    Updated: 2021/09/28 16:28:49 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		sources/parse/ft_parse_map.c \
		sources/parse/ft_parse_map2.c \
		sources/error_free/ft_error.c \
		sources/error_free/ft_free_map.c \
		sources/gnl/get_next_line.c \
		sources/basic_function/ft_strlen.c \
		sources/basic_function/ft_putstr.c \
		sources/basic_function/ft_strdup.c \
		sources/game/ft_init_game.c

OBJS	= $(SRCS:.c=.o)

NAME	= solong

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
LIBS	= -LminilibX -lmlx -framework OpenGL -framework AppKit -lm
MLX		= libmlx.dylib

all:		$(NAME)

%.o : %.c
	${CC} ${CFLAGS} -I./includes -I./minilibX -c $< -o $@

$(NAME):	${MLX} $(OBJS)
		${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

$(MLX) :
		$(MAKE) -C minilibX
		@cp minilibX/$(MLX)	.

$(OBJS):	includes/solong.h includes/get_next_line.h minilibX/mlx.h

clean:
		$(MAKE) -C minilibX clean
		$(RM) libmlx.dylib
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re