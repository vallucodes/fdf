# NAME		= Game
# CFLAGS		= -g -Wextra -Wall -Werror -Wunreachable-code
# LIBMLX		= ./lib/MLX42
# GNL			= ./src/gnl
# OBJ_DIR		= obj/
# SRC_DIR		= src/

# HEADERS		= -I ./include -I $(LIBMLX)/include -I $(GNL)
# LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS		= $(shell find src -iname "*.c" | sed 's|^\./||')
# OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
# DEPS		= $(shell find include -iname "*.h")

# all: $(OBJ_DIR) libmlx $(NAME)

# $(OBJ_DIR):
# 		@mkdir -p $(OBJ_DIR)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# $(NAME): $(OBJF) $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -rf $(OBJ_DIR)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx


NAME		= Game
CFLAGS		= -g -Wextra -Wall -Werror -Wunreachable-code
LIBMLX		= ./lib/MLX42
LIBFTDIR 	= ./libft
LIBFT 		= $(LIBFTDIR)/libft.a
GNL			= ./src/gnl
OBJ_DIR		= obj/
SRC_DIR		= src/

HEADERS		= -I ./include -I $(LIBMLX)/include -I $(GNL) -I $(LIBFT)
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS		= $(shell find src -iname "*.c" | sed 's|^\./||')
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS		= $(shell find include -iname "*.h")

all: $(OBJ_DIR) libmlx $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJF) $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(LIBFT)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx
