NAME = cubtest

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_NAMES = main.c movements.c parse_map.c gnl.c gnl_utils.c utils.c line_utils.c map_utils.c map_check.c
SRC = $(addprefix ./src/, $(SRC_NAMES))
OBJ = $(addprefix ./obj/, $(SRC_NAMES:.c=.o))

MLX_DIR = mlx_linux
MLX = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
INCLUDES = -I$(MLX_DIR) -I/usr/include  -Iinclude -Ilibft
LIBFT =  -Llibft -lft
OBJ_DIR := ./obj

all: libft-all $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

./obj/%.o: ./src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

libft-clean:
	$(MAKE) -C libft clean
libft-fclean:
	$(MAKE) -C libft fclean
libft-all:
	$(MAKE) -C libft all

clean: libft-clean cub3d-clean

cub3d-clean:
	rm -f $(OBJ)

fclean: libft-fclean cub3d-clean
	rm -f $(NAME)

re: fclean all
