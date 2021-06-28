#include "so_long.h"

void	map_size(t_map *map)
{
	char	*line;
	int		fd;
	int		gnl;

	map->height = 1;
	fd = open("map.ber", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		map->height++;
		free(line);
	}
	map->width = ft_strlen(line);
	free(line);
	close(fd);
}

void	get_map(t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		i;
	t_map	*map;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	map = malloc(sizeof(t_map));
	map_size(map);
	map->maparr = malloc((int)sizeof(char*) * map->height);
	while ((get_next_line(fd, &line)) > 0)
	{
		map->maparr[i++] = ft_strdup(line);
		free(line);
		if (ft_strlen(map->maparr[i - 1]) != map->width)
		{
			perror("The Map is not rectangular. Error\n");
			exit(EXIT_FAILURE);
		}
		printf("IN_MAP : %s\n", map->maparr[i - 1]);
	}
	map->maparr[i] = ft_strdup(line);
	free(line);
	printf("IN_MAP : %s\n", map->maparr[i]);
	close(fd);
	mlx->map = map;
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	ft_memset(mlx->check, 0, sizeof(t_check));
	set_images(mlx);
	i = 0;
	j = 0;
	while (i < mlx->map->height)
	{
		while (j < mlx->map->width)
		{
			if (mlx->map->maparr[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->wall, j * BITSIZE , i * BITSIZE);
			else if (mlx->map->maparr[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->collectible, j * BITSIZE , i * BITSIZE);
				mlx->check->collectible_num++;
			}
			else if (mlx->map->maparr[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->exitp, j * BITSIZE , i * BITSIZE);
				mlx->check->exitp_num++;
			}
			else if (mlx->map->maparr[i][j] == 'P')
			{
				mlx->map->curi = i;
				mlx->map->curj = j;
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->map->player, j * BITSIZE , i * BITSIZE);
				mlx->check->player_num++;
			}
			else if (mlx->map->maparr[i][j] != '0')
			{
				perror("The map has invalid character. Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = 0;
	}
	printf("C : %d\nE : %d\nP : %d\n", mlx->check->collectible_num, mlx->check->exitp_num,mlx->check->player_num);
}
