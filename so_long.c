#include "so_long.h"
int		move_character(int keycode, t_mlx *mlx)
{
	// if (keycode == W)
	// {

	// }
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
		exit(0);//정상종료 찾아볼것
	}
	return 0;
}

void	make_wall(t_mlx *mlx)
{
	t_img	*wall;
	int		bitsize;

	bitsize = 64;
	wall = malloc(sizeof(t_img));
	wall->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/wall.xpm", &bitsize, &bitsize);
	mlx->map->wall = wall;
}

int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	get_map(mlx);
    mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "test");
//위에 얘가 세그폴트
	// for (int size = 0; size <= 0; size++)
	// {
		// mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->wall->img_ptr, 0 , 0);
	// }
	// // mlx_hook(mlx->window, KEYPRESS, 0, &move_character, mlx);
	mlx_loop(mlx->mlx_ptr);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
