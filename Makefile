NAME		= Game
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		= ./lib/MLX42
OBJ_DIR		= obj/
SRC_DIR		= src/

HEADERS		= -I ./include -I $(LIBMLX)/include
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS		= $(shell find src -iname "*.c" | sed 's|^\./||')
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(OBJ_DIR) libmlx $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJF) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
