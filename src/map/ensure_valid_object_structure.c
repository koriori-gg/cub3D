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

static bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
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
		if (!has_valid_object_in_line(map[i]))
			exit_with_error("Invalid object on the map\n");
		while (map[i][j] != '\0')
		{
			if (is_player(map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		exit_with_error("Only one player is allowed on the map\n");
}
