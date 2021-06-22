#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

#include <stdlib.h>
#include "minilibx_mms_20200219/mlx.h"

# define KEYPRESS 2
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
}				t_mlx;

typedef struct s_img
{
	// void	*mlx;
	// void	*window;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;


#endif