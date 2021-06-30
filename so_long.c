#include "so_long.h"

int		finish_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void		move_player(t_mlx *mlx, int	*idx, char c)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx->map->maparr[mlx->map->curi][mlx->map->curj] = '0';
	if (c == '-')
		(*idx)--;
	else if (c == '+')
		(*idx)++;
	if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'E' && \
	0 < mlx->check->collectible_num)
	{
		if (c == '-')
			(*idx)++;
		else if (c == '+')
			(*idx)--;
		mlx->map->maparr[mlx->map->curi][mlx->map->curj] = 'P';
		draw_map(mlx);
		return ;
	}
	if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'E' \
	|| mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'B')
		finish_game(mlx);
	if (mlx->map->maparr[mlx->map->curi][mlx->map->curj] == 'C')
		mlx->check->collectible_num--;
	mlx->map->maparr[mlx->map->curi][mlx->map->curj] = 'P';
	draw_map(mlx);
}

int		get_key(int keycode, t_mlx *mlx)
{
	if (keycode == W && mlx->map->maparr[mlx->map->curi - 1][mlx->map->curj] != '1')
	{
		mlx->check->curkey = 'W';
		move_player(mlx, &mlx->map->curi, '-');
	}
	if (keycode == S && mlx->map->maparr[mlx->map->curi + 1][mlx->map->curj] != '1')
	{
		mlx->check->curkey = 'S';
		move_player(mlx, &mlx->map->curi, '+');
	}
	if (keycode == A && mlx->map->maparr[mlx->map->curi][mlx->map->curj - 1] != '1')
	{
		mlx->check->curkey = 'A';
		move_player(mlx, &mlx->map->curj, '-');
	}
	if (keycode == D && \
	mlx->map->maparr[mlx->map->curi][mlx->map->curj + 1] != '1')
	{
		mlx->check->curkey = 'D';
		move_player(mlx, &mlx->map->curj, '+');
	}
	if (keycode == ESC)
		finish_game(mlx);
	return (0);
}

int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	mlx->check = malloc(sizeof(t_check));
	get_map(mlx);
	mlx->mlx_ptr = mlx_init();
	set_window(mlx);
	draw_map(mlx);
	check(mlx);
	mlx_hook(mlx->window, KEYPRESS, 0, &get_key, mlx);
	mlx_hook(mlx->window, REDCROSS, 0, &finish_game, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &change_image, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
