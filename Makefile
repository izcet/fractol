# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 17:39:00 by irhett            #+#    #+#              #
#    Updated: 2017/06/03 19:01:28 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
XFLAGS		=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
FLAGS		=	$(CFLAGS) $(XFLAGS)

SRC_DIR		=	src
SRC_FILE	=	main.c redraw.c spawn.c \
				color.c color1.c color2.c color3.c color4.c \
				equals.c \
				image.c thread.c window.c input_structs.c \
				init_hooks.c key_hooks.c mouse_hooks.c sys_hooks.c \
				zoom.c \
				mandelbrot.c
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

MLX_DIR	=	mlx
MLX_LIB	=	libmlx.a
MLX		=	$(MLX_DIR)/$(MLX_LIB)

LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a
LIBFT_INC	=	includes
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

INC_DIR		=	-I $(LIBFT_DIR)/$(LIBFT_INC) -I $(MLX_DIR) -I inc

.PHONY: mlx libft all clean fclean re

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(MLX) $(LIBFT) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@cd $(MLX_DIR) && make clean
	@cd $(LIBFT_DIR) && make clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
