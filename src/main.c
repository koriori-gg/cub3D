#include "cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//TODO: add free
	exit(0);
}

void	init_struct(t_game *game)
{
	// game->player->position_x = 22;
	// game->player->position_y = 12;
	// game->player->direction_x = -1;
	// game->player->direction_y = 0;
	// game->player->plane_x = 0;
	// game->player->plane_y = 2;
	game->time = 0;
	game->oldtime = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 1000, "cub3D");
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

// }

int main(void)
{
	t_game	game;

	printf("hgoe\n");
	init_struct(&game);
	mlx_key_hook(game.win, input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	// mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
