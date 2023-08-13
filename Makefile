NAME = cub3d

LIBS = -L/usr/X11R6/lib -lX11 -lXext

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a \
	$(MLX_DIR)/libmlx_Darwin.a

CC = cc
INCLUDES = -I $(LIBFT_DIR)/include -I include -I minilibx-linux
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRCS = src/main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBS) $(LIBFT) $(MLX) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
