# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 15:22:34 by livsauze          #+#    #+#              #
#    Updated: 2024/06/01 13:03:23 by livsauze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LINK = -Llibft -lft -lXext -lX11 -lm

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = ${MLX_PATH}${MLX_NAME}
INC =	-I ./include/\
		-I ./libft/\
		#-I ./minilibx-linux/\

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3

UTILS = utils/ft_exit.c utils/ft_maths.c
SRCS = ${UTILS} src/main.c src/ft_errors.c src/ft_events.c src/ft_init.c \
		src/ft_render.c
OBJS = ${SRCS:.c=.o}

%.o : %.c
		${CC} ${CFLAGS} ${INC} -c $< -o $@

${NAME} : ${OBJS}
		make -sC ${MLX_PATH}
		make -C libft/
		${CC} ${CFLAGS} ${INC} ${OBJS} ${MLX} ${LINK} -o ${NAME}
all : ${NAME}

clean :
		rm -f ${OBJS}
		make clean -C libft/
		make -C ${MLX_PATH} clean


fclean : clean
		make fclean -C libft/
		rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
		
