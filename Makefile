NAME = cubtest

CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c movements.c parse_map.c gnl.c gnl_utils.c utils.c line_utils.c\
draw_fts.c
OBJ = $(SRC:.c=.o)

MLX_DIR = mlx_linux
MLX = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES = -I$(MLX_DIR) -I/usr/include

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
