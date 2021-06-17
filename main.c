#include "./minilibx_mms_20200219/mlx.h"
#include <stdlib.h>


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;


void	put_pixel(t_img *img, int x, int y, int color)
{
	void	*dst;

	dst = img->addr + ((y * img->line_length) + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void 	*mlx;
	void 	*window;
	t_img	*img;

    mlx = mlx_init();
	img = malloc(sizeof(t_img));
	img->bits_per_pixel = 1;
	img->line_length = 1920;
    window = mlx_new_window(mlx, 1920, 1080, "test");
	img->img = mlx_new_image(mlx, 500, 500);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	for (int i = 0; i < 100; i++)
	{
		put_pixel(img, i, i, 0x000000FF);
	}
	mlx_put_image_to_window(mlx, window, img->img, 500, 500);
	mlx_loop(mlx);
}

