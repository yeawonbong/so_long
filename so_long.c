#include "so_long.h"

int		finish_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_window(t_mlx *mlx)
{
	mlx->x = mlx->map->width * BITSIZE;
	mlx->y = mlx->map->height * BITSIZE;
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->x, mlx->y, "test");
}

void	set_images(t_mlx *mlx)
{
	int		bitsize;

	bitsize = 64;
	mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/codewall.xpm", &bitsize, &bitsize);
	mlx->map->collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/mac.xpm", &bitsize, &bitsize);
	mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/player.xpm", &bitsize, &bitsize);	
	mlx->map->exitp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/bye.xpm", &bitsize, &bitsize);
}

int		move_character(int keycode, t_mlx *mlx)
{
	if (keycode == W && mlx->map->maparr[mlx->map->curi - 1][mlx->map->curj] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = '0';
		mlx->map->curi--;
		if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'E')
			finish_game(mlx);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = 'P';
		draw_map(mlx);
	}
	if (keycode == S && mlx->map->maparr[mlx->map->curi + 1][mlx->map->curj] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = '0';
		mlx->map->curi++;
		if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'E')
			finish_game(mlx);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = 'P';
		draw_map(mlx);
	}
	if (keycode == A && mlx->map->maparr[mlx->map->curi][mlx->map->curj - 1] != '1')
	{
		if (mlx->map->maparr[mlx->map->curi][mlx->map->curj - 1] == 'C')
			mlx->check->collectible_num--;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = '0';
		mlx->map->curj--;
		if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'E')
			finish_game(mlx);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = 'P';
		draw_map(mlx);
	}
	if (keycode == D && mlx->map->maparr[mlx->map->curi][mlx->map->curj + 1] != '1')
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = '0';
		mlx->map->curj++;
		if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'E')
			finish_game(mlx);
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = 'P';
		draw_map(mlx);
	}
	if (keycode == ESC)
		finish_game(mlx);
	return 0;
}
//void		parse_map(t_mlx *mlx)


int	main(void)
{
	t_mlx	*mlx;

	
	mlx = malloc(sizeof(t_mlx));
	mlx->check = malloc(sizeof(t_check));
	get_map(mlx);
    mlx->mlx_ptr = mlx_init();
	set_window(mlx);
	draw_map(mlx);
	check(mlx->check);
	mlx_hook(mlx->window, KEYPRESS, 0, &move_character, mlx);
	mlx_hook(mlx->window, REDCROSS, 0, &finish_game, mlx);
	mlx_loop(mlx->mlx_ptr);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
