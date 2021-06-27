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

// typedef struct s_img
// {
// 	void	*wall;
// 	void	*collectible;
// 	void	*player;
// 	void	*exitp;
// }			t_img;

typedef struct	s_map
{
	char	**maparr;
	int		width;
	int		height;

	void	*wall;
	void	*collectible;
	void	*player;
	char	*playerp;
	void	*exitp;

}				t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	int		x;
	int		y;
	t_map	*map;
}				t_mlx;

/*
**	so_long.c
*/
void	set_window(t_mlx *mlx);
void	set_images(t_mlx *mlx);
void	destroy_images(t_mlx *mlx);
int		move_character(int keycode, t_mlx *mlx);
void	draw_map(t_mlx *mlx);

char	*error_exit();
void	map_size(t_map *map);
void	get_map(t_mlx *mlx);

#endif