#include "cub3d.h"


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

void	check_wall(char **map)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = make_map_copy(map);
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0')
				search_reachable_squares(map_copy, i, j);
			j++;
		}
		i++;
	}
	free_double_pointer(map_copy);
}

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	is_floor_or_wall(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	return (false);
}

void	validate_map(char **map)
{
	int	player_count;
	int	i;
	int	j;

	print_two_dimensional_array(map);
	player_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_player(map[i][j]))
				player_count++;
			else if (!is_floor_or_wall(map[i][j]))
				exit_with_error("invalid object in map\n");
			j++;
		}
		i++;
	}
	if (player_count != 1)
		exit_with_error("too many players\n");
	check_wall(map);
}
