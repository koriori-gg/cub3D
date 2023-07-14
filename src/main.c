#include "cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//TODO: add free
	exit(0);
}

void	init_struct(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 1000, "cub3D");
}

int main(void)
{
	t_game	game;

	init_struct(&game);
	// mlx_key_hook(game->win, input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop(game.mlx);
}
