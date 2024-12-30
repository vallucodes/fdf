NAME = a.out
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME) clean

SOURCES = \
		get_next_line_utils.c get_next_line.c map_parsing.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
