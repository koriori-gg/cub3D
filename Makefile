NAME = project

CC = cc

CFLAGS = -I include -I libft/include -Wall -Wextra -Werror

RM = rm -f

SRCS = src/main.c

LIBFT_DIR = libft

LIBFT_OBJ = $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS)  $(INCLUDE)-c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) -L. $(LIBFT_OBJ) $(OBJS) 

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
