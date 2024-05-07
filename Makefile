# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 15:22:34 by livsauze          #+#    #+#              #
#    Updated: 2024/05/07 12:25:11 by livsauze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LINK = -Llibft -lft -lXext -lX11 -lm

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = ${MLX_PATH} ${MLX_NAME}
INC =	-I ./include/\
		-I ./libft/\
		-I ./minilibx-linux/\

CC = cc
CFLAGS = Wall -Werror -Wextra -g

UTILS =
SRCS = ${UTILS}
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
		make -C ${MLX} clean


fclean : clean
		rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
		