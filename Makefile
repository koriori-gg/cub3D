NAME = cub3D

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a \
	$(MLX_DIR)/libmlx_Darwin.a

SRCS = src/main.c \
	src/exit_with_error.c \
	src/open_cub_file.c \
	src/get_map_info.c \
	src/input_key.c \
	src/error/error.c \
	src/error/free.c \
	src/utils/print_debug.c \
	src/setup/init_struct.c \
	src/setup/ft_xpm_to_image.c \
	src/raycasting/calculate.c \
	src/raycasting/calculate_dda.c \
	src/raycasting/save_color.c \
	src/raycasting/save_floor_and_ceiling.c \
	src/raycasting/char_to_int.c \
	src/raycasting/draw.c \
	src/minimap/draw_map.c \

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