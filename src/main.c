#include "cub3d.h"

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q cub3d");
}

// debug
void	print_info(t_cub_info info)
{
	printf("north_texture = %s\n", info.north_texture);
	printf("south_texture = %s\n", info.south_texture);
	printf("west_texture = %s\n", info.west_texture);
	printf("east_texture = %s\n", info.east_texture);
	printf("floor_color = %d, %d, %d\n", info.floor_color[0], info.floor_color[1], info.floor_color[2]);
	printf("ceiling_color = %d, %d, %d\n", info.ceiling_color[0], info.ceiling_color[1], info.ceiling_color[2]);
}

void	free_cub_info(t_cub_info cub_info)
{
	free(cub_info.north_texture);
	free(cub_info.south_texture);
	free(cub_info.west_texture);
	free(cub_info.east_texture);
	// free_double_pointer(cub_info.map);
}

int main(int argc, char *argv[])
{
	t_cub_info	cub_info;

	if (argc != 2)
		exit_with_error("invalid input");
	cub_info = read_cub(argv[1]);
	print_info(cub_info);
	free_cub_info(cub_info);
	return (0);
}