# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 23:26:16 by jchacon-          #+#    #+#              #
#    Updated: 2025/11/08 23:39:51 by jchacon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRC = src

OBJ = obj
OBJ_FILES	:=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

RM = rm -f

# Libraries
LIBFT_DIR	:= includes/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

MINILIBX_DIR	:= includes/minilibx-linux
MINILIBX	:= $(MINILIBX_DIR)/libmlx_Linux.a

all: $(NAME)
# Compiles source into obj
$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensures obj/ exists
$(OBJ):
	mkdir -p $(OBJ)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MINILIBX) -lX11 -lXext -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)
	
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	
re: fclean all
	
.PHONY: all clean fclean re