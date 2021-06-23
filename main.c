
#include "so_long.h"


// void	get_map(t_mlx *mlx, const char *filename)
// {
// 	char	**line;
// 	int		gnl;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open(filename, O_RDONLY);
// 	mlx->map = malloc((int)sizeof(char*) * mlx->y);

// 	while ((gnl = get_next_line(fd, line)) > 0)
// 	{
// 		mlx->map[i++] = ft_strdup(*line);
// 		free(*line);
// 	}
// 	mlx->map[i] = ft_strdup(*line);
// 	free(*line);
// }


int	main(void)
{
	char	**line;
	int		fd = 0;
	int		gnl;

	char	**map;
	int		i;
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->y = 10;
	i = 0;

	*line = NULL;
	map = malloc((int)sizeof(char*) * mlx->y);
	// get_map(mlx, "map.ber");
	fd = open("map.ber", O_RDONLY);
	printf("fd = %d\n", fd);
	while ((gnl = get_next_line(fd, line)) > 0)
	{
		// printf("line in map = %s\n", *line);
		map[i++] = ft_strdup(*line);
		printf("IN_MAP : %s\n", map[i - 1]);
		free(*line);
	}
	map[i++] = ft_strdup(*line);
	printf("IN_MAP : %s\n", map[i - 1]);

	free(*line);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}

