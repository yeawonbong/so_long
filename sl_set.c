#include "so_long.h"

void	set_window(t_mlx *mlx)
{
	mlx->x = mlx->map->width * BITSIZE;
	mlx->y = mlx->map->height * BITSIZE;
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->x, mlx->y, "test");
	mlx->check->curkey = 'S';
	mlx->check->collectible_num = -1;
}

void	set_player(t_mlx *mlx)
{
	int		bitsize;

	bitsize = 64;
  	if (mlx->check->collectible_num > mlx->change * 2 || mlx->check->collectible_num == -1)
	{
		if (mlx->check->curkey == 'S')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'W')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/playerw.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'A')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/playera.png", &bitsize, &bitsize);        
		else if (mlx->check->curkey == 'D')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/playerd.png", &bitsize, &bitsize);        
	}
	else if (mlx->check->collectible_num > mlx->change)
	{
		if (mlx->check->curkey == 'S')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player2.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'W')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player2w.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'A')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player2a.png", &bitsize, &bitsize);        
		else if (mlx->check->curkey == 'D')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player2d.png", &bitsize, &bitsize);        
	}
	else
	{
		if (mlx->check->curkey == 'S')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player3.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'W')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player3w.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'A')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player3a.png", &bitsize, &bitsize);        
		else if (mlx->check->curkey == 'D')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/player/player3d.png", &bitsize, &bitsize);        
	}
}

int 	set_images(t_mlx *mlx)
{
	int		bitsize;

	bitsize = 64;
	set_player(mlx);
	if (20 < mlx->loop)
	{
		mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/wall/codewall.xpm", &bitsize, &bitsize);
		mlx->map->exitp = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/bye.png", &bitsize, &bitsize);
		mlx->map->blackhole = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/blackhole/blackhole.png", &bitsize, &bitsize);
		mlx->map->collectible = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/collec/mac.png", &bitsize, &bitsize);	
	}
	else
	{
		mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/wall/codewall2.xpm", &bitsize, &bitsize);
		mlx->map->exitp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/bye.xpm", &bitsize, &bitsize);       
		mlx->map->blackhole = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/blackhole/blackhole2.png", &bitsize, &bitsize);
		mlx->map->collectible = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/collec/mac2.png", &bitsize, &bitsize);	
	}
	mlx->map->floor = mlx_png_file_to_image(mlx->mlx_ptr, "./image_sources/space.png", &bitsize, &bitsize);       
	return (0);
}

int 	change_image(t_mlx *mlx)
{
	mlx->loop++;
	if (mlx->loop == 40)
		mlx->loop = 0;
	set_images(mlx);
	draw_map(mlx);
	return (0);
}
