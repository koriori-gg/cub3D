#include "cub3d.h"

// __attribute__((destructor))
// void    destructor(void)
// {
//     system("leaks cub3d");
// }

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//TODO: add free
	exit(0);
}

int	main_loop(t_game *game)
{
	draw_map(game);
	calculate(game);
	draw(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	printf("argc : %d\n", argc);
	// validate_argument(argc, argv);
	init_struct(&game, argv);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L<<0, &input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
