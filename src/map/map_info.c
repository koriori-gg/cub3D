#include "cub3d.h"

void	free_map_info(t_mapinfo *map_info)
{
	//add:
	free(map_info->north_texture);
	free(map_info->south_texture);
	free(map_info->west_texture);
	free(map_info->east_texture);
	free(map_info->floor_color);
	free(map_info->ceiling_color);
	ft_free_map(map_info->map);
	free(map_info);
}
