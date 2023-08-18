NAME = cub3D

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a \
	$(MLX_DIR)/libmlx_Darwin.a

SRCS = src/main.c \
	src/input_key.c \
	src/error/validate_argument.c \
	src/error/validate_map.c \
	src/error/able_to_goal.c \
	src/error/error.c \
	src/error/free.c \
	src/map/map.c \
	src/map/init_mapinfo.c \
	src/map/mapinfo_operator.c \
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

OBJ = $(SRCS:%.c=%.o)

CC = cc

LIBS = -L/usr/X11R6/lib -lX11 -lXext

INCLUDES = -I $(LIBFT_DIR)/include -I include -I minilibx-linux

CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

# ifeq ($(shell uname), Darwin)
# XFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
# MLX = $(MLX_DIR)/libmlx_Darwin.a
# else
# XFLAGS = -Lmlx -Llibft -L/usr/X1R6/lib -lXext -lX11 -lm
# MLX = $(MLX_DIR)/libmlx.a #TODO:check必要
# endif

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBS) $(OBJ) $(LIBFT) $(MLX)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJ)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PONEY: all clean fclean re