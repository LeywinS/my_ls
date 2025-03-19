CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = my_ls.c options.c display.c sorting.c list.c
OBJ = $(SRC:.c=.o)
NAME = my_ls

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
