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

int input_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		printf("up\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		printf("left\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		printf("down\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		printf("right\n");
	return (0);
}

// int	main_loop(t_game *game)
// {
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_game	game;

	printf("argc : %d\n", argc);
	validate_argument(argc, argv);
	init_struct(&game, argv);
	mlx_key_hook(game.win, input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	// mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
