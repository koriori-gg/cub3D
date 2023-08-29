#include "cub3d.h"

static char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;
	int		height;

	height = 0;
	while (map[height])
		height++;
	map_copy = calloc(height + 1, sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
			return (NULL);
		i++;
	}
	return (map_copy);
}

static void	search_reachable_grids(char **map, int height, int i, int j)
{
	if (i < 0 || j < 0 || i >= height || j >= (int)ft_strlen(map[i]) || ft_isspace(map[i][j]))
		exit_with_error("The map is not enclosed by wall\n");
	if (map[i][j] == '1' || map[i][j] == '2')
		return ;
	map[i][j] = '2';
	search_reachable_grids(map, height, i, j + 1);
	search_reachable_grids(map, height, i + 1, j);
	search_reachable_grids(map, height, i, j - 1);
	search_reachable_grids(map, height, i - 1, j);
}

void	ensure_map_enclosed_by_wall(char **map)
{
	char	**map_copy;
	int		height;
	int		i;
	int		j;

	map_copy = copy_map(map);
	height = 0;
	while (map_copy[height])
		height++;
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
				search_reachable_grids(map_copy, height, i, j);
			j++;
		}
		i++;
	}
	free_double_pointer(map_copy);
}
