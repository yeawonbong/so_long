/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 05:29:36 by ybong             #+#    #+#             */
/*   Updated: 2021/06/23 20:55:11 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	**line;
	int		fd = 0;
	int		gnl;

	*line = NULL;
	fd = open("map.ber", O_RDONLY);
	printf("fd = %d\n", fd);
	while ((gnl = get_next_line(fd, line)) > 0)
	{
		printf("line = %s\n", *line);
		free(*line);
	}
	printf("line = %s\n", *line);
	free(*line);
	// system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}

