NAME = cub3D

LIBFT_DIR = libft
LIBFT_OBJ = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_OBJ = $(MLX_DIR)/libmlx_Darwin.a

SRC = 01/main.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -I minilibx-linux -I include -I libft/include -I /opt/X11/include #-Wall -Wextra -Werror

ifeq ($(shell uname), Darwin)
XFLAGS = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MLX_OBJ = $(MLX_DIR)/libmlx_Darwin.a
else
XFLAGS = -Lmlx -Llibft -L/usr/X1R6/lib -lXext -lX11 -lm
MLX_OBJ = $(MLX_DIR)/libmlx.a #TODO:check必要
endif

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ) $(MLX_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_OBJ) $(MLX_OBJ) $(XFLAGS)

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

$(MLX_OBJ):
	make -C $(MLX_DIR)


clean:
	$(RM) $(OBJ)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PONEY: all clean fclean re