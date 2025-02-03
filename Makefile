NAME		= fdf
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code

MLX_DIR		= ./lib/MLX42
MLX			= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR 	= ./libft
LIBFT 		= $(LIBFT_DIR)/libft.a
GNL_DIR		= ./src/gnl

OBJ_DIR		= obj/
SRC_DIR		= src/

HEADERS		= -I ./inc -I $(MLX_DIR)/include -I $(GNL_DIR) -I $(LIBFT_DIR)
MLXLIB		= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC			=	color_gradient.c color_points.c draw_current.c draw_line.c \
				error.c hooks.c initiate.c main.c map_operations.c \
				ops_move_scale.c ops_rotate.c parse_height_width.c parse_row.c parse.c \
				gnl/get_next_line_utils.c gnl/get_next_line.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

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

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(MLXLIB) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re
