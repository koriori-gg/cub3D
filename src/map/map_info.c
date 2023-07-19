#include "cub3d.h"

void	free_map_info(t_mapinfo *map_info)
{
	//add:
	ft_free_map(map_info->map);
	free(map_info->map);
	free(map_info);
}
