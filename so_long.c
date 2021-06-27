#include "so_long.h"

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
	mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/temp_c.xpm", &bitsize, &bitsize);	
	mlx->map->exitp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/docker.xpm", &bitsize, &bitsize);
}

void	destroy_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->wall);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->collectible);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->player);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map->exitp);
}

int		move_character(int keycode, t_mlx *mlx)
{
	if (keycode == W)
	{
		// destroy_images(mlx);
		printf("PLAYER P : %s\n", mlx->map->playerp);
		*(mlx->map->playerp) = '0';
		// mlx->map->playerp = mlx->map->playerp - mlx->x;
		// *(mlx->map->playerp) = 'P';
		printf("W키 들어오긴 함. \n");
		draw_map(mlx);
	}
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
		exit(0);//정상종료 찾아볼것
	}
	return 0;
}
//void		parse_map(t_mlx *mlx)

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	set_images(mlx);
	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < mlx->map->width)
		{
			// if (mlx->map->map[i][j] == '0')
			// 	break ;
			if (mlx->map->maparr[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->wall, j * BITSIZE , i * BITSIZE);
			else if (mlx->map->maparr[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->collectible, j * BITSIZE , i * BITSIZE);
			else if (mlx->map->maparr[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->exitp, j * BITSIZE , i * BITSIZE);
			else if (mlx->map->maparr[i][j] == 'P')
			{
				mlx->map->playerp = &mlx->map->maparr[i][j];
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->player, j * BITSIZE , i * BITSIZE);
			}
			j++;
		}
		i++;
		j = 0;
	}
}


int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	get_map(mlx);
    mlx->mlx_ptr = mlx_init();
	set_window(mlx);
	draw_map(mlx);




	mlx_hook(mlx->window, KEYPRESS, 0, &move_character, mlx);
	mlx_loop(mlx->mlx_ptr);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
