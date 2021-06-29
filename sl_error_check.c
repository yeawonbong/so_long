/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:59:10 by ybong             #+#    #+#             */
/*   Updated: 2021/06/29 18:02:15 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*maperror()
{
	perror("The map is invalid. Error\n");
	exit(EXIT_FAILURE);
}

void	check_wall(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width && \
		(i == 0 || i == mlx->map->height - 1))
		{
			if (mlx->map->maparr[i][j] != '1')
				maperror();
			j++;	
		}
		if (mlx->map->maparr[i][0] != '1' || mlx->map->maparr[i][mlx->map->width - 1] != '1')
			maperror();
		i++;
	}
}

void	check(t_mlx *mlx)
{
	if (mlx->check->collectible_num < 1 || mlx->check->exitp_num < 1 \
	|| mlx->check->player_num != 1)
		maperror();
	check_wall(mlx);
	mlx->check->change = mlx->check->collectible_num / 3;
}
