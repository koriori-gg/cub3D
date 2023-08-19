#include "cub3d.h"

__attribute__((destructor))
void	destructor(void)
{
	system("leaks -q cub3d");
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(0);
}

int	main_loop(t_game *game)
{
	draw_map(game);
	calculate(game);
	draw(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		exit_with_error("invalid input");
	fd = open_cub_file(argv[1]);
	init_game(&game, fd);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, &input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
