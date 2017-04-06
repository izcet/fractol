#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 19:11:40 by irhett            #+#    #+#              #
#    Updated: 2017/04/04 19:11:40 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
XFLAGS		=	#-flags -for -X
FLAGS		=	$(CFLAGS) $(XFLAGS)

SRC_DIR		=	src
SRC_FILE	=	##!!##
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

LIBFT_DIR	=	libft
MLX_DIR	=	mlxLIBFT_DIR	=	libft
MLX_LIB	=	mlx.a #assuming project is named the sameLIBFT_DIR	=	libft
MLX_INC	=	#includes directory, if applicableLIBFT_DIR	=	libft
MLX		=	$(MLX_DIR)/$(MLX_LIB)LIBFT_DIR	=	libft
LIBFT_DIR	=	libft
LIBFT_LIB	=	libft.a #assuming project is named the same
LIBFT_INC	=	#includes directory, if applicable
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

INC_DIR		=	-I $(LIBFT_DIR)/$(LIBFT_INC) -I $(MLX_DIR)/$(MLX_INC) -I inc

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

fclean:
	@cd $(MLX_DIR) && make fclean
	@cd $(LIBFT_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
NAME		=	fractol

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
XFLAGS		=	#-flags -for -X
FLAGS		=	$(CFLAGS) $(XFLAGS)

SRC_DIR		=	src
SRC_FILE	=	##!!##
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC_DIR		=	-I $(MLX_DIR)/$(MLX_INC) -I inc

.PHONY: mlx all clean fclean re

all: $(MLX) $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CC) $(FLAGS) $(MLX) $(OBJS) $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -c $^ $(CFLAGS) $(INC_DIR) -o $@

clean:
	@cd $(MLX_DIR) && make clean
	@rm -rf $(OBJ_DIR)

fclean:
	@cd $(MLX_DIR) && make fclean
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
