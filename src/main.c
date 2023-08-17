#include "cub3d.h"

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q cub3d");
}

void	free_cub_info(t_cub_info cub_info)
{
	free(cub_info.north_texture);
	free(cub_info.south_texture);
	free(cub_info.west_texture);
	free(cub_info.east_texture);
	free_double_pointer(cub_info.map);
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
