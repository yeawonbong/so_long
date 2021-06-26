#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

#include <stdlib.h>
#include "./minilibx_mms_20200219/mlx.h"
#include "./get_next_line/get_next_line.h"

# define KEYPRESS 2
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define BITSIZE 64

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct	s_map
{
	void	**map;
	int		width;
	int		height;

	int		collectible;
	int		exitp;
	int		startp;
	t_img	*wall;
}				t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	int		x;
	int		y;
	t_map	*map;
}				t_mlx;

char	*error_exit();
void	map_size(t_map *map);
void	get_map(t_mlx *mlx);

#endif