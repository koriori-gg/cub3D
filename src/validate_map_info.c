#include "cub3d.h"

// 全てboolにするか検討
static void	validate_texture_path(char *texture_path)
{
	if (!texture_path)
		exit_with_error("texture path not found");
}

static void	validate_rgb(int *rgb)
{
	if (!rgb)
		exit_with_error("rgb not found");
}

static void	validate_map(char **map)
{
	if (!map)
		exit_with_error("map not found");
}

void	validate_map_info(t_map_info map_info)
{
	validate_texture_path(char *texture_path);
	validate_rgb(int *rgb);
	validate_map(char **map);
}