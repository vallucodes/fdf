NAME = a.out
CC = cc
INCLUDES	= -Ignl
CFLAGS = -Wall -Werror -Wextra

all: $(NAME) clean

SOURCES = \
		gnl/get_next_line_utils.c gnl/get_next_line.c map_parsing.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

gnl/%.o: gnl/%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

%.o: %.c
	$(CC) $(INCLUDES) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
