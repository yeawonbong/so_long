#include "so_long.h"

int		finish_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	exit(EXIT_SUCCESS);
	return (0);
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

int	main(void)
{
	t_mlx	*mlx;
	
	mlx = malloc(sizeof(t_mlx));
	// ft_memset(mlx, 0, sizeof(t_mlx));
	mlx->check = malloc(sizeof(t_check));
	get_map(mlx);
    mlx->mlx_ptr = mlx_init();
	set_window(mlx);
	set_images(mlx);
	draw_map(mlx);
	check(mlx);
	mlx_hook(mlx->window, KEYPRESS, 0, &move_character, mlx);
	mlx_hook(mlx->window, REDCROSS, 0, &finish_game, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &change_image, mlx);//
	mlx_loop(mlx->mlx_ptr);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
