# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:12:13 by lbrianna          #+#    #+#              #
#    Updated: 2022/03/25 13:59:18 by lbrianna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRCS = srcs/so_long.c srcs/parser1.c\
	srcs/parser2.c 	srcs/get_next_line.c\
	srcs/get_next_line_utils.c srcs/ft_split.c\
	srcs/utils.c 	srcs/free.c srcs/game1.c\
	srcs/game_move.c	srcs/game_go.c\

SRCS_BONUS = srcs_bonus/so_long.c srcs_bonus/parser1.c\
	srcs_bonus/parser2.c 	srcs_bonus/get_next_line.c\
	srcs_bonus/get_next_line_utils.c srcs_bonus/ft_split.c\
	srcs_bonus/utils.c 	srcs_bonus/free.c srcs_bonus/game1.c\
	srcs_bonus/game_move.c	srcs_bonus/game_go.c srcs_bonus/animation.c\
	srcs_bonus/ft_itoa.c srcs_bonus/enemy_up_down.c srcs_bonus/enemy_left_right.c\

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

PRINTF = ft_printf/libftprintf.a
INCLUDES = includes/
HEADER = so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM =  rm -rf
MLX = -L mlx -lmlx -framework OpenGL -framework AppKit

all: 	printf $(NAME)
bonus: 	printf $(NAME_BONUS)

printf:
	@make -C ft_printf/
	
%.o : %.c $(INCLUDES)$(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

mlx: 
	@$(MAKE) -C mlx

$(NAME): mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  $(PRINTF) $(MLX) -o $(NAME)

$(NAME_BONUS) : mlx $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(PRINTF) $(MLX) -o $(NAME_BONUS)
clean:
	@make clean -C ./mlx
	@make -C ft_printf/ clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C ft_printf/ fclean
	$(RM) $(NAME)  $(NAME_BONUS) $(OBJS_BONUS)

re: fclean all
	@make re -C ./mlx

.PHONY : all clean fclean re bonus printf