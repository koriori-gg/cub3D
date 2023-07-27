#include "cub3d.h"

void	print_argv(char **argv)
{
	int	i;

	printf("==argv==\n");
	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
}

// void	print_map(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	printf("--map--\n");
// 	map = map->next;//変更する
// 	while (map)
// 	{
// 		if (i < 10)
// 			printf("[  %d] %s",i, map->row);
// 		else if (i < 100)
// 			printf("[ %d] %s",i, map->row);
// 		else if (i < 1000)
// 			printf("[%d] %s",i, map->row);
// 		map = map->next;
// 		i++;
// 	}
// }

void	print_map(t_map *map)
{
	printf("--map--\n");
	while (map)
	{
		if (map->y < 10)
			printf("[  %zu] %s", map->y, map->row);
		else if (map->y < 100)
			printf("[ %zu] %s", map->y, map->row);
		else if (map->y < 1000)
			printf("[%zu] %s", map->y, map->row);
		map = map->next;
	}
}

void	print_map_info(t_mapinfo *map_info)
{
	printf("== map info ==\n");
	printf("NO: %s\n", map_info->north_texture);
	printf("SO: %s\n", map_info->south_texture);
	printf("WE: %s\n", map_info->west_texture);
	printf("EA: %s\n", map_info->east_texture);
	printf("F :r %d, g %d, b %d\n", map_info->floor_color->red, map_info->floor_color->green, map_info->floor_color->blue);
	printf("C :r %d, g %d, b %d\n", map_info->ceiling_color->red, map_info->ceiling_color->green, map_info->ceiling_color->blue);
	print_map(map_info->map);
}