NAME = fillit
SRC = main.c reader_1.c list_deleter.c solver.c validation.c map.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra

.PHONY: all fclean clean re

all: $(NAME)

%.o:%.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
