NAME = so_long

CFLAGS = -Wall -Wextra -Werror

CC = cc

CFILS = flood_fill.c ft_check_map.c ft_player.c ft_split.c  util_functions.c

$(NAME): $(CFILS)
	$(CC) $(CFLAGS) $(CFILS) -o $(NAME)

all: $(NAME)

clean:
	$(NAME)

fclean: clean

re: fclean all