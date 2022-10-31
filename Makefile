NAME = so_long

SRC = main.c so_long.c get_next_line.c get_next_line_utils.c mov_player.c check_map.c

all: $(NAME)

$(NAME): $(SRC) get_next_line.h
	gcc -Wall -Wextra -Werror -Imlx  -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)
	
re: fclean all
