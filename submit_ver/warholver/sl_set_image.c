/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_set_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:07:51 by ybong             #+#    #+#             */
/*   Updated: 2021/07/01 20:45:09 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		set_images(t_mlx *mlx)
{
	int		bitsize;

	bitsize = 64;
	set_player(mlx);
	if (20 < mlx->loop)
	{
		mlx->map->wall = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/wall/blackwall.png", &bitsize, &bitsize);
		mlx->map->exitp = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/exit/warhol.png", &bitsize, &bitsize);
		mlx->map->blackhole = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/blackhole/hole.png", &bitsize, &bitsize);
		mlx->map->collectible = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/collec/paint.png", &bitsize, &bitsize);
	}
	else
		set_images2(mlx);
	mlx->map->floor = mlx_png_file_to_image(mlx->mlx_ptr, \
	"./img/floor.png", &bitsize, &bitsize);
	return (0);
}

void	set_images2(t_mlx *mlx)
{
	int		bitsize;

	bitsize = 64;
	mlx->map->wall = mlx_png_file_to_image(mlx->mlx_ptr, \
	"./img/wall/blackwall.png", &bitsize, &bitsize);
	mlx->map->exitp = mlx_png_file_to_image(mlx->mlx_ptr, \
	"./img/exit/warhol2.png", &bitsize, &bitsize);
	mlx->map->blackhole = mlx_png_file_to_image(mlx->mlx_ptr, \
	"./img/blackhole/hole.png", &bitsize, &bitsize);
	mlx->map->collectible = mlx_png_file_to_image(mlx->mlx_ptr, \
	"./img/collec/paint2.png", &bitsize, &bitsize);
}

void	set_player(t_mlx *mlx)
{
	int		bitsize;

	bitsize = BITSIZE;
	if (mlx->check->collectible_num > mlx->change * 2 \
	|| mlx->check->collectible_num == -1)
	{
		if (mlx->check->curkey == 'S')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
			"./img/player/monroe.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'W')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
			"./img/player/monroew.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'A')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
			"./img/player/monroea.png", &bitsize, &bitsize);
		else if (mlx->check->curkey == 'D')
			mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
			"./img/player/monroed.png", &bitsize, &bitsize);
	}
	else if (mlx->check->collectible_num > mlx->change)
		set_player2(mlx);
	else
		set_player3(mlx);
}

void	set_player2(t_mlx *mlx)
{
	int	bitsize;

	bitsize = BITSIZE;
	if (mlx->check->curkey == 'S')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroe2.png", &bitsize, &bitsize);
	else if (mlx->check->curkey == 'W')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroepw.png", &bitsize, &bitsize);
	else if (mlx->check->curkey == 'A')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroe2a.png", &bitsize, &bitsize);
	else if (mlx->check->curkey == 'D')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroe2d.png", &bitsize, &bitsize);
}

void	set_player3(t_mlx *mlx)
{
	int	bitsize;

	bitsize = BITSIZE;
	if (mlx->check->curkey == 'S')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroe3.png", &bitsize, &bitsize);
	else if (mlx->check->curkey == 'W')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroepw.png", &bitsize, &bitsize);
	else if (mlx->check->curkey == 'A')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroe3a.png", &bitsize, &bitsize);
	else if (mlx->check->curkey == 'D')
		mlx->map->player = mlx_png_file_to_image(mlx->mlx_ptr, \
		"./img/player/monroe3d.png", &bitsize, &bitsize);
}
