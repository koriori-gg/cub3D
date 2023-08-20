#include "cub3d.h"

// 全てboolにするか検討
static void	validate_texture_path(char *texture_path)
{
	if (!texture_path)
		exit_with_error("texture path not found");
}

static void	validate_rgb(int *rgb)
{
	int	i;

	if (!rgb)
		exit_with_error("invalid RGB");
	i = 0;
	while (rgb[i])
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			exit_with_error("invalid RGB");
		i++;
	}
}

int	check_object(char object)
{
	if (object == 'N' || object == 'S' || object == 'E' || object == 'W')
		return (1);
	else if(object != '0' && object != '1' && object != ' ')
		exit_with_error("invalid object\n");
	return (0);
}

// 壁に囲まれているか
// 01NSEWのみで構成されているか
static void	validate_map(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			count += check_object(map[i][j]);
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_with_error("too many players\n");
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
