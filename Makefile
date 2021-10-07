# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:43:06 by ngeschwi          #+#    #+#              #
#    Updated: 2021/10/07 15:46:14 by ngeschwi         ###   ########.fr        #
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
		sources/game/ft_init_game.c \
		sources/game/ft_create_map.c \
		sources/game/ft_command_up_down.c \
		sources/game/ft_command_left_right.c \
		sources/game/ft_end.c

OBJS	= $(SRCS:.c=.o)

OBJ_PATH := objets

PATH_OBJS := $(addprefix $(OBJ_PATH)/, $(OBJS))

NAME	= so_long

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra -g3 #-fsanitize=address
LIBS	= -LminilibX -lmlx -framework OpenGL -framework AppKit -lm
MLX		= libmlx.dylib
LINK	= -Iincludes -IminilibX

all:		$(NAME)

%.o : %.c | $(OBJ_PATH)
	${CC} ${CFLAGS} ${LINK} -c $< -o objets/$@

$(NAME):	${MLX} $(OBJS)
		${CC} ${CFLAGS} ${PATH_OBJS} ${LINK} ${LIBS} -o ${NAME}

$(OBJ_PATH) :
		mkdir -p objets
		mkdir -p objets/sources
		mkdir -p objets/sources/basic_function
		mkdir -p objets/sources/error_free
		mkdir -p objets/sources/game
		mkdir -p objets/sources/gnl
		mkdir -p objets/sources/parse

$(MLX) :
		$(MAKE) -C minilibX
		@cp minilibX/$(MLX)	.

$(OBJS):	includes/solong.h includes/get_next_line.h minilibX/mlx.h

clean:
		$(MAKE) -C minilibX clean
		$(RM) libmlx.dylib
		$(RM) $(PATH_OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re