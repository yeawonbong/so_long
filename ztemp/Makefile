SRCS = so_long.c\
sl_map.c\
sl_set_mlx.c\
sl_set_image.c\
sl_error_check.c\
sl_utils.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = so_long.a
OBJS = $(SRCS:.c=.o)
OUT = so_long

GNL = get_next_line.a
GNL_DIR = ./get_next_line
MLX = libmlx.dylib
MLX_DIR = ./minilibx_mms_20200219

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(GNL_DIR)
	make all -C $(MLX_DIR)
	@cp $(GNL_DIR)/$(GNL) $(NAME)
	@cp $(MLX_DIR)/$(MLX) .
	$(AR) $@ $(OBJS)
	$(CC) $(CFLAGES) $(NAME) $(MLX) -o $(OUT)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGES) -c $(SRCS) -I $(GNL_DIR)

clean : 
	make clean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(GNL_DIR)
	rm -rf $(NAME) $(OUT)
	rm -f $(MLX)
 
re : fclean all

.PHONU : all clean fclean re