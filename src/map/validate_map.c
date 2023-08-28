#include "cub3d.h"

void	validate_map(char **map)
{
	ensure_valid_object_structure(map);
	ensure_map_enclosed_by_wall(map);
}
