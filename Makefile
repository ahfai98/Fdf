# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 15:35:53 by jyap              #+#    #+#              #
#    Updated: 2024/05/17 15:56:16 by jyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLFAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
AR = ar rcs
SRC_DIR = src
INC = -I ./inc/ -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
OBJ_DIR = obj
LIBFT = libft.a
LIBFT_DIR = libft
MINILIBX_DIR = minilibx_macos
LIBRARIES = -L$(LIBFT_DIR) -lft -lm -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
NAME = fdf

SRC =	main.c \
		render.c \
		bresenham.c \
		parsing.c \
		ft_atoi_base.c \
		rotation.c \
		translate_resize.c \
		handle_key_event.c \
		transformation_utils.c \
		color_n_gradient.c \
		render_ortho.c \
		free.c \
		render_text_info.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBRARIES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .

$(MINILIBX):
	make -C $(MINILIBX_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
