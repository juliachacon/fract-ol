# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julia <julia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 02:02:37 by julia             #+#    #+#              #
#    Updated: 2025/11/09 23:59:35 by julia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./includes -I./includes/libft -I./includes/minilibx-linux


# Directorios
SRC_DIR     = src
OBJ_DIR     = obj

# Lista de ficheros .c (SOLO el nombre, sin "src/")
# >>> CAMBIA ESTA LÍNEA CON TUS .C <<<
SRC_FILES   = main.c init.c utils.c

# Construimos rutas completas
SRCS        = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

RM          = rm -f

# Libraries
LIBFT_DIR       = includes/libft
LIBFT           = $(LIBFT_DIR)/libft.a

MINILIBX_DIR    = includes/minilibx-linux
MINILIBX        = $(MINILIBX_DIR)/libmlx_Linux.a

# -------------------- Reglas -------------------- #

all: $(NAME)

# Asegura que obj/ existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilar .c de src/ en .o dentro de obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Enlazar todo
$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -lX11 -lXext -lm -o $(NAME)

# Compilar libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar minilibx
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
