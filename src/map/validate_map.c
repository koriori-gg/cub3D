#include "cub3d.h"

static bool	has_valid_object_in_line(char *line)
{
	if (ft_strchr(line, '0'))
		return (true);
	else if (ft_strchr(line, '1'))
		return (true);
	else if (ft_strchr(line, 'N'))
		return (true);
	else if (ft_strchr(line, 'S'))
		return (true);
	else if (ft_strchr(line, 'W'))
		return (true);
	else if (ft_strchr(line, 'E'))
		return (true);
	return (false);
}

static bool	has_empty_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!has_valid_object_in_line(map[i]))
			return (true);
		i++;
	}
	return (false);
}

void	validate_map(char **map)
{
	check_player_count(map);
	if (has_empty_line(map))
		exit_with_error("map error: map has empty line\n");
	ensure_map_enclosed_by_wall(map);
}
