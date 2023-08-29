#include "cub3d.h"

static char	**copy_map(char **map)
{
	char	**map_copy;
	int		i;
	int		height;

	i = 0;
	while (map[i])
		i++;
	height = i;
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

static void	search_reachable_grids(char **map, int i, int j)
{
	if (j >= (int)ft_strlen(map[i]) || map[i][j] == ' ')
		exit_with_error("The map must be surrounded by wall\n");
	if (map[i][j] == '1' || map[i][j] == '2')
		return ;
	map[i][j] = '2';
	search_reachable_grids(map, i, j + 1);
	search_reachable_grids(map, i + 1, j);
	search_reachable_grids(map, i, j - 1);
	search_reachable_grids(map, i - 1, j);
}

void	ensure_map_enclosed_by_wall(char **map)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = copy_map(map);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
				search_reachable_grids(map_copy, i, j);
			j++;
		}
		i++;
	}
	free_double_pointer(map_copy);
}
