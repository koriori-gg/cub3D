#include "cub3d.h"

static bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static bool	is_floor_or_wall(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (true);
	return (false);
}

static bool	are_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isspace(line[i]))
			return (true);
		i++;
	}
	return (false);
}

void	ensure_valid_object_structure(char **map)
{
	int	player_count;
	int	i;
	int	j;

	player_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		if (!are_spaces(map[i]))
			exit_with_error("Invalid map structure");
		while (map[i][j] != '\0')
		{
			if (is_player(map[i][j]))
				player_count++;
			else if (!is_floor_or_wall(map[i][j]))
				exit_with_error("Invalid object on the map\n");
			j++;
		}
		i++;
	}
	if (player_count != 1)
		exit_with_error("Only one player is allowed on the map\n");
}
