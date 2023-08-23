#include "cub3d.h"

int	check_object(char object)
{
	if (object == 'N' || object == 'S' || object == 'E' || object == 'W')
		return (1);
	else if(object != '0' && object != '1' && object != ' ')
		exit_with_error("invalid object\n");
	return (0);
}

char	**make_map_copy(char **map)
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

void	search_reachable_squares(char **map, int i, int j)
{
	if (j >= (int)ft_strlen(map[i]) || map[i][j] == ' ')
		exit_with_error("gomimap\n");
	if (map[i][j] == '1' || map[i][j] == '2')
		return ;
	map[i][j] = '2';
	search_reachable_squares(map, i, j + 1);
	search_reachable_squares(map, i + 1, j);
	search_reachable_squares(map, i, j - 1);
	search_reachable_squares(map, i - 1, j);
}

void	check_wall(char **map, int y, int x)
{
	char	**map_copy;

	map_copy = make_map_copy(map);
	search_reachable_squares(map, y, x);
	free_double_pointer(map_copy);
}

// 0を基準にする
static void	validate_map(char **map)
{
	int	count;
	int	i;
	int	j;
	int x, y;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_object(map[i][j]))
			{
				x = j;
				y = i;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_with_error("too many players\n");
	check_wall(map, y, x);
}

void	validate_map_info(t_map_info map_info)
{
	validate_texture_path(map_info.north_texture);
	validate_texture_path(map_info.south_texture);
	validate_texture_path(map_info.west_texture);
	validate_texture_path(map_info.east_texture);
	validate_rgb(map_info.floor_color);
	validate_rgb(map_info.ceiling_color);
	validate_map(map_info.map);
}