#include "so_long.h"


typedef struct s_img
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

int		move_character(int keycode, t_img *img)
{
	if (keycode == W)
	{

	}
	if (keycode == ESC)
	{
		mlx_destroy_window(img->mlx, img->window);
		exit(0);//정상종료 찾아볼것
	}
	return 0;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	void	*dst;

	dst = img->addr + ((y * img->line_length) + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{

	t_img	*img;

	img = malloc(sizeof(t_img));
    img->mlx = mlx_init();
	img->bits_per_pixel = 1;
	img->line_length = 1920;
	img->window = mlx_new_window(img->mlx, 1920, 1080, "test");
	img->img = mlx_new_image(img->mlx, 192, 108);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	for (int i = 0; i <= 192; i++)
	{
		for (int j = 0; j <= 108; j++)
			put_pixel(img, i, j, 0x000000FF);
	}
	for (int size = 0; size <= 10; size++)
	{
		mlx_put_image_to_window(img->mlx, img->window, img->img, 192 * size, 0);
	}
	mlx_hook(img->window, KEYPRESS, 0, &move_character, img);
	mlx_loop(img->mlx);
	return 0;
}
