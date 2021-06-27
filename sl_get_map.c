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
	printf("MAP HEIGHT IS : %d\nMAP WIDTH IS : %d\n", map->height, map->width);
}

void	get_map(t_mlx *mlx)
{
	char	*line;
	int		fd;
	int		i;
	t_map	*map;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	printf("fd = %d\n", fd);

	map = malloc(sizeof(t_map));
	map_size(map);
	map->maparr = malloc((int)sizeof(char*) * map->height);
	while ((get_next_line(fd, &line)) > 0)
	{
		map->maparr[i++] = ft_strdup(line);
		free(line);
		if (ft_strlen(map->maparr[i - 1]) != map->width)
		{
			perror("The Map is not rectangular");
		}
		printf("IN_MAP : %s\n", map->maparr[i - 1]);
	}
	map->maparr[i] = ft_strdup(line);
	free(line);
	printf("IN_MAP : %s\n", map->maparr[i]);
	mlx->map = map;
	close(fd);
}

