#include "cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 1000, "cub3D");
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop(game.mlx);
}
