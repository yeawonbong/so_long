#include "so_long.h"

void	map_size(t_map *map)
{
	char	*line;
	int		fd;
	int		gnl;

	map->height = 1;
	fd = open("map.ber", O_RDONLY);
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		if (gnl <= 0)
			break ;
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
	map->maparr = malloc((int) sizeof(char *) * map->height);
	while ((get_next_line(fd, &line)) > 0)
	{
		map->maparr[i++] = ft_strdup(line);
		free(line);
		if (ft_strlen(map->maparr[i - 1]) != map->width)
		{
			perror("The Map is not rectangular. Error\n");
			exit(EXIT_FAILURE);
		}
	}
	map->maparr[i] = ft_strdup(line);
	free(line);
	close(fd);
	mlx->map = map;
}

void	draw_10b(t_mlx *mlx, int i, int j)
{
	if (mlx->map->maparr[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->wall, j * BITSIZE, i * BITSIZE);
	else if (mlx->map->maparr[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->floor, j * BITSIZE, i * BITSIZE);
	else if (mlx->map->maparr[i][j] == 'B')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->blackhole, j * BITSIZE, i * BITSIZE);
}

void	draw_cep(t_mlx *mlx, int i, int j)
{
	if (mlx->map->maparr[i][j] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->collectible, j * BITSIZE, i * BITSIZE);
		mlx->check->collectible_num++;
	}
	else if (mlx->map->maparr[i][j] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->exitp, j * BITSIZE, i * BITSIZE);
		mlx->check->exitp_num++;
	}
	else if (mlx->map->maparr[i][j] == 'P')
	{
		mlx->map->curi = i;
		mlx->map->curj = j;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, \
		mlx->map->player, j * BITSIZE, i * BITSIZE);
		mlx->check->player_num++;
	}
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	set_images(mlx);
	ft_memset(mlx->check, 0, sizeof(t_check));
	i = 0;
	j = 0;
	while (i < mlx->map->height)
	{
		while (j < mlx->map->width)
		{
			if (ft_strchr("10B", mlx->map->maparr[i][j]))
				draw_10b(mlx, i, j);
			else if (ft_strchr("CEP", mlx->map->maparr[i][j]))
				draw_cep(mlx, i, j);
			else
			{
				perror("The map has invalid character. Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
