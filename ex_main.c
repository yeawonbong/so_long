
#include "so_long.h"

char	*error_exit()
{

	return ("Error\n");
}

// void	map_size(t_map *map)
// {
// 	char	*line;
// 	int		fd;
// 	int		gnl;

// 	map->height = 1;
// 	fd = open("map.ber", O_RDONLY);
// 	while ((gnl = get_next_line(fd, &line)) > 0)
// 	{
// 		map->height++;
// 		free(line);
// 	}
// 	map->width = ft_strlen(line);
// 	free(line);
// 	close(fd);
// 	printf("MAP HEIGHT IS : %d\nMAP WIDTH IS : %d\n", map->height, map->width);
// }

// t_map	*get_map(t_mlx *mlx, int fd)
// {
// 	char	*line;
// 	int		gnl;
// 	int		i;
// 	t_map	*map;

// 	i = 0;
// 	map = malloc(sizeof(t_map));
// 	map_size(map);
// 	map->map = malloc((int)sizeof(char*) * map->height);
// 	while ((gnl = get_next_line(fd, &line)) > 0)
// 	{
// 		map->map[i++] = ft_strdup(line);
// 		free(line);
// 		if (ft_strlen(map->map[i - 1]) != map->width)
// 		{
// 			perror("The Map is not rectangular");
// 		}
// 		printf("IN_MAP : %s\n", map->map[i - 1]);
// 	}
// 	map->map[i] = ft_strdup(line);
// 	free(line);
// 	printf("IN_MAP : %s\n", map->map[i]);
// 	mlx->map = map;
// 	close(fd);
// 	return (map);
// }

int	main(void)
{
	char	**line;
	int		fd;
	int		gnl;

	int		i;
	t_mlx	*mlx;

	i = 0;
	mlx = malloc(sizeof(t_mlx));

	*line = NULL;
	fd = open("map.ber", O_RDONLY);
	printf("fd = %d\n", fd);
	get_map(mlx, fd);
	// t_img wall = malloc(sizeof(img));
	// wall->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./image_sources/wall.xpm", 5,5);
	// mlx_put_image_to_window
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
