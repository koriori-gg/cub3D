#include "cub3d.h"

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q cub3d");
}

void	free_map_info(t_map_info map_info)
{
	free(map_info.north_texture);
	free(map_info.south_texture);
	free(map_info.west_texture);
	free(map_info.east_texture);
	free(map_info.floor_color);
	free(map_info.ceiling_color);
	free_double_pointer(map_info.map);
}

static void	init_map_info(t_map_info *map_info)
{
	map_info->north_texture = NULL;
	map_info->south_texture = NULL;
	map_info->west_texture = NULL;
	map_info->east_texture = NULL;
	map_info->floor_color = NULL;
	map_info->ceiling_color = NULL;
	map_info->map = NULL;
}

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	int			fd;

	if (argc != 2)
		exit_with_error("invalid input");
	init_map_info(&map_info);
	fd = open_cub_file(argv[1]);
	map_info = get_map_info(fd);
	validate_map_info(map_info);
	free_map_info(map_info);
	return (0);
}
