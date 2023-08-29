# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 14:30:24 by ihashimo          #+#    #+#              #
#    Updated: 2023/08/29 14:30:24 by ihashimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a \
	$(MLX_DIR)/libmlx_Darwin.a

SRCS = src/main.c \
	src/error/exit_with_error.c \
	src/error/open_cub_file.c \
	src/error/free.c \
	src/utils/print_debug.c \
	src/utils/try_mlx.c \
	src/setup/init_struct.c \
	src/setup/init_minimap.c \
	src/setup/init_asset.c \
	src/setup/init_player.c \
	src/raycasting/calculate_field_of_view.c \
	src/raycasting/calculate_collision_grid.c \
	src/raycasting/save_color.c \
	src/raycasting/prepare_map_draw.c \
	src/raycasting/save_floor_and_ceiling.c \
	src/raycasting/draw_field_of_view.c \
	src/map/draw_minimap.c \
	src/map/validate_map.c \
	src/map/ensure_valid_object_structure.c \
	src/map/ensure_map_enclosed_by_wall.c \
	src/map/get_map_info.c \
	src/map/input_key.c \

OBJS = $(SRCS:%.c=%.o)

CC = cc

LIBS = -L/usr/X11R6/lib -lX11 -lXext

INCLUDES = -I $(LIBFT_DIR)/include -I include -I minilibx-linux

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBS) $(OBJS) $(LIBFT) $(MLX)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PONEY: all clean fclean re