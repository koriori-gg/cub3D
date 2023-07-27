#include "cub3d.h"

static void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	game->player->position_x = 12;//本来はmapから読み取る必要あり
	game->player->position_y = 5;
	game->player->direction_x = -1;
	game->player->direction_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
	game->player->move_speed = 0.05;
	game->player->rot_speed = 0.05;
}

void	init_struct(t_game *game, char **argv)
{
	init_player(game);
	game->map_info = init_mapinfo(argv);//initのやり方統一した方がいい??
	print_map_info(game->map_info);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 1000, "cub3D");
}
