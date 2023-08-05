#include "cub3d.h"

void	free_map(t_map *map)
{
	t_map	*ptr;

	while (map)
	{
		ptr = map;
		map = map->next;
		free(ptr->row);
		free(ptr);
	}
}

void	free_mapinfo(t_mapinfo *map_info)
{
		free(map_info->north_texture);
		free(map_info->south_texture);
		free(map_info->west_texture);
		free(map_info->east_texture);
		free(map_info->floor_color);
		free(map_info->ceiling_color);
		free(map_info);
		free_map(map_info->map);
}

void	free_struct(t_game *game)
{
	free(game->player);
	free_mapinfo(game->map_info);
}