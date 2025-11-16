# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 02:02:37 by julia             #+#    #+#              #
#    Updated: 2025/11/16 17:34:03 by jchacon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name (final executable)
NAME        = fractol

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./includes -I./includes/libft -I./includes/minilibx-linux

# Directories for sources and objects
SRC_DIR     = src
OBJ_DIR     = obj

# Source files located in src/
SRC_FILES   = main.c init.c mandelbrot.c julia.c \
			 draw.c utils.c mouse_keys.c ft_atof.c

# Bonus = mandatory + burning_ship.c
SRC_BONUS   = main_bonus.c init.c mandelbrot.c julia.c \
              draw.c utils.c mouse_keys.c ft_atof.c burning_ship.c

# Objetos mandatory y bonus
MANDATORY_OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
BONUS_OBJS     = $(addprefix $(OBJ_DIR)/,$(SRC_BONUS:.c=.o))

# Remove command
RM          = rm -f

# -------------------- Libraries -------------------- #

# libft
LIBFT_DIR       = includes/libft
LIBFT           = $(LIBFT_DIR)/libft.a

# MiniLibX
MINILIBX_DIR    = includes/minilibx-linux
MINILIBX        = $(MINILIBX_DIR)/libmlx_Linux.a

# -------------------- Rules -------------------- #

# Default rule: build the main executable
all: $(NAME)

# Ensure the object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile each .c from src/ into a .o inside obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files with libraries to create the executable
$(NAME): $(MANDATORY_OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) $(MINILIBX) -lX11 -lXext -lm -o $(NAME)

# Build libft (static library)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build MiniLibX
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

# -------------------- Bonus -------------------- #
# Para bonus cambiamos la lista de objetos que se linkean:
bonus: $(BONUS_OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MINILIBX) -lX11 -lXext -lm -o $(NAME)

# -------------------- Cleaning -------------------- #
# Remove object files and call clean in sub-libraries
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

# Full clean: remove objects, executable, and libft library
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

# Rebuild everything from scratch
re: fclean all

# Targets that do not correspond to actual files
.PHONY: all bonus clean fclean re
