NAME = so_long

#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

CC = cc

CFILS = flood_fill.c ft_check_map.c ft_player.c ft_split.c  util_functions.c main.c so_long.c

#$(CFLAGS)

$(NAME): $(CFILS)
	$(CC)  $(CFLAGS) $(CFILS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
