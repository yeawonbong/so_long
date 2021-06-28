#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

#include <stdlib.h>
#include "./minilibx_mms_20200219/mlx.h"
#include "./get_next_line/get_next_line.h"

# define KEYPRESS 2
# define REDCROSS 17
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define BITSIZE 64

typedef struct	s_check
{
	int		collectible_num;
	int		player_num;
	int		exitp_num;
	int		change;
}				t_check;

typedef struct	s_map
{
	char	**maparr;
	int		width;
	int		height;

	void	*wall;
	void	*collectible;
	void	*player;
	void	*exitp;

	int		curi;
	int		curj;
}				t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	int		x;
	int		y;
	t_map	*map;
	t_check	*check;
}				t_mlx;

/*
**	so_long.c
*/
int		finish_game(t_mlx *mlx);
void	set_window(t_mlx *mlx);
void	set_images(t_mlx *mlx);
int		move_character(int keycode, t_mlx *mlx);
int		main(void);

/*
**	sl_get_map.c
*/
void	map_size(t_map *map);
void	get_map(t_mlx *mlx);
void	draw_map(t_mlx *mlx);

/*
**	sl_error_check.c
*/
void	*maperror();
void	check_wall(t_map *map);
void	check(t_check *check);


#endif