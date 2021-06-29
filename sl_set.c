#include "so_long.h"

void	set_window(t_mlx *mlx)
{
	mlx->x = mlx->map->width * BITSIZE;
	mlx->y = mlx->map->height * BITSIZE;
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->x, mlx->y, "test");
}

int 	set_images(t_mlx *mlx)
{
	int		bitsize;

	bitsize = 64;
    if (20 < mlx->loop)
    {
        mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/codewall.xpm", &bitsize, &bitsize);
        mlx->map->collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/mac.xpm", &bitsize, &bitsize);
        mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/player.xpm", &bitsize, &bitsize);	
        mlx->map->exitp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/bye.xpm", &bitsize, &bitsize);
    }
    else
    {
        mlx->map->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/codewall2.xpm", &bitsize, &bitsize);
        mlx->map->collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/mac.xpm", &bitsize, &bitsize);
        mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/player.xpm", &bitsize, &bitsize);	
        mlx->map->exitp = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/bye.xpm", &bitsize, &bitsize);       
    }
    // if (mlx->map->collectible < mlx->check->change)
    //     mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/player.xpm", &bitsize, &bitsize);        
    // else if (mlx->map->collectible < mlx->check->change * 2)
    //     mlx->map->player = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/player.xpm", &bitsize, &bitsize);
    return (0);
}


int 	change_image(t_mlx *mlx)
{
	mlx->loop++;
    if (mlx->loop == 40)
        mlx->loop = 0;
    set_images(mlx);
    draw_map(mlx);
    printf("LOOP %d\n", mlx->loop);
    return (0);
}
