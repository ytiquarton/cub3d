NAME := libft.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I.
INCLUDES := includes
SRC_DIR := .
OBJ_DIR := .
SOURCES := $(addprefix $(SRC_DIR)/, $(addprefix ./, ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c \
ft_strlcat.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c \
ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c \
ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c) \
$(addprefix ./, ft_itoa.c ft_putendl_fd.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c \
ft_substr.c ft_putchar_fd.c ft_putnbr_fd.c ft_split.c ft_strjoin.c ft_strtrim.c))

OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

re: fclean all


$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@


clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

.PHONY: all clean re fclean