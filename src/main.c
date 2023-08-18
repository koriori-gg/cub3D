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

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//TODO: add free
	exit(0);
}

int	main_loop(t_game *game)
{
	// draw_map(game);
	calculate(game);
	draw(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;
	// t_map_info	map_info;
	// int			fd;

	if (argc != 2)
		exit_with_error("invalid input");
	/*---------*/
	// init_map_info(&map_info);
	// fd = open_cub_file(argv[1]);
	// map_info = get_map_info(fd);
	// print_info(map_info);
	// free_map_info(map_info);
	/*---------*/

	printf("argc : %d\n", argc);
	// validate_argument(argc, argv);
	init_struct(&game, argv);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L<<0, &input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
