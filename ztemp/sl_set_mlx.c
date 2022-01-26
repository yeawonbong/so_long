/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_set_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:08:11 by ybong             #+#    #+#             */
/*   Updated: 2021/07/05 20:25:11 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_window(t_mlx *mlx)
{
	mlx->x = mlx->map->width * BITSIZE;
	mlx->y = mlx->map->height * BITSIZE;
	mlx->window = mlx_new_window(mlx->mlx_ptr, mlx->x, mlx->y, "test");
	mlx->check->curkey = 'S';
	mlx->check->collectible_num = -1;
}

int		loop_draw(t_mlx *mlx)
{
	mlx->loop++;
	if (mlx->loop == 40)
		mlx->loop = 0;
	set_images(mlx);
	draw_map(mlx);
	return (0);
}

void	rewrite_map(t_mlx *mlx, char *filename)
{
	int	fd;
	int i;
	int j;

	i = 0;
	j = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("Error\nThe map doesn't exist");
		exit(EXIT_FAILURE);
	}
	while (i < mlx->map->height)
	{
		write(fd, mlx->map->maparr[i], mlx->map->width);
		if (mlx->map->maparr[i + 1])
			write(fd, "\n", 1);
		i++;
	}
}