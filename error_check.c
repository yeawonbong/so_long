/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:59:10 by ybong             #+#    #+#             */
/*   Updated: 2021/06/28 22:21:09 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*maperror()
{
	perror("The map is invalid. Error\n");
	exit(EXIT_FAILURE);
}

void	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width && \
		(i == 0 || i == map->height - 1))
		{
			if (map->maparr[i][j] != '1')
				maperror();
			j++;	
		}
		if (map->maparr[i][0] != '1' || map->maparr[i][map->width - 1] != '1')
			maperror();
		i++;
	}
}

void	check(t_check *check)
{
	if (check->collectible_num < 1 || check->exitp_num < 1 \
	|| check->player_num != 1)
		maperror();
	check_wall(map);
	check->change = check->collectible_num / 3;
}
