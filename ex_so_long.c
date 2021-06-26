
#include "so_long.h"

// int		move_character(int keycode, t_mlx *mlx)
// {
// 	// if (keycode == W)
// 	// {

// 	// }
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(mlx->mlx_ptr, mlx->window);
// 		exit(0);//정상종료 찾아볼것
// 	}
// 	return 0;
// }

void	put_pixel(t_img *img, int x, int y, int color)
{
	void	*dst;

	dst = img->addr + ((y * img->line_length) + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



// int main(void)
// {
// 	t_mlx	*mlx;
// 	t_img	*img;
// 	t_map	*map;
// 	int q=64;
// 	int w=64;
// 	char	*line;
// 	int		fd;
// 	int		gnl;
	
	// t_img *wall;
	// wall = malloc(sizeof(img));
	// wall->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/wall.xpm", &q,&w);
	// mlx = malloc(sizeof(t_mlx));
	// img = malloc(sizeof(t_img));
    // mlx->mlx_ptr = mlx_init();
	// mlx->window = mlx_new_window(mlx->mlx_ptr, map->width * 64, map->height * 64, "test");

	// map = get_map(mlx, fd);


	img->bits_per_pixel = 1;
	img->line_length = 1920;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, 192, 108);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);

	// for (int i = 0; i <= 192; i++)
	// {
	// 	for (int j = 0; j <= 108; j++)
	// 		put_pixel(img, i, j, 0x000000FF);
	// }
	// for (int size = 0; size <= 10; size++)
	// {
	// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, img->img_ptr, 192 * size, 0);
	// }

// 	//
// 	for (int size = 0; size <= 10; size++)
// 	{
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, wall->img_ptr, 64 * size,0);
// 	}
// 	//
// 	mlx_hook(mlx->window, KEYPRESS, 0, &move_character, mlx);
// 	mlx_loop(mlx->mlx_ptr);
// 	return 0;
// }
