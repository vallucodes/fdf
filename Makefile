NAME		= Game
CFLAGS		= -g -Wextra -Wall -Werror -Wunreachable-code

#Libraries
MLX_DIR		= ./lib/MLX42
MLX			= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR 	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a
GNL_DIR		= ./src/gnl

OBJ_DIR		= obj/
SRC_DIR		= src/

HEADERS		= -I ./inc -I $(MLX_DIR)/include -I $(GNL_DIR) -I $(LIBFT_DIR)
LIBS		= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC			=	colors.c draw_current.c draw_line.c error.c \
				gradient.c hooks.c initiate.c main.c parsing.c \
				ops_move_scale.c ops_rotate.c parsing_utils.c small_operations.c \
				gnl/get_next_line_utils.c gnl/get_next_line.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC))
OBJS		= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

#make libraries
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX): $(MLX_DIR)
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@make -C $(MLX_DIR)/build -j4

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git $@;

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT) $(OBJ_DIR) $(MLX)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(LIBFT)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re
