#include "cub3d.h"

void	validate_map(char **map)
{
	check_player_count(map);
	ensure_map_enclosed_by_wall(map);
}
