#include "cub3d.h"

// norminette not applied

void	print_info(t_map_info info)
{
	printf("------ DEBUG: print_info ------\n");
	printf("north_texture = %s\n", info.north_texture);
	printf("south_texture = %s\n", info.south_texture);
	printf("west_texture = %s\n", info.west_texture);
	printf("east_texture = %s\n", info.east_texture);
	printf("floor_color = %d, %d, %d\n", info.floor_color[0], info.floor_color[1], info.floor_color[2]);
	printf("ceiling_color = %d, %d, %d\n", info.ceiling_color[0], info.ceiling_color[1], info.ceiling_color[2]);
	print_two_dimensional_array(info.map);
}

void	print_two_dimensional_array(char **array)
{
	int	i;

	i = 0;
	printf("------ DEBUG: print_two_dimensional_array ------\n");
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
