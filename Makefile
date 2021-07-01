SRCS = so_long.c\
sl_map.c\
sl_set.c\
sl_set_image.c\
sl_error_check.c\
ft_itoa.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = so_long.a
OBJS = $(SRCS:.c=.o)
OUT = so_long

GNL = get_next_line.a
GNL_DIR = ./get_next_line
MLX = libmlx.dylib

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C get_next_line
	@cp $(GNL_DIR)/$(GNL) $(NAME)
	$(AR) $@ $(OBJS)
	$(CC) $(CFLAGES) $(NAME) $(MLX) -o $(OUT)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGES) -c $(SRCS) -I $(GNL_DIR)

clean : 
	make clean -C $(GNL_DIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(GNL_DIR)
	rm -rf $(NAME) $(OUT)
 
re : fclean all

.PHONU : all clean fclean re