NAME    = gnl
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
BUFFER  = 42

SRC     = get_next_line.c get_next_line_utils.c main.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re