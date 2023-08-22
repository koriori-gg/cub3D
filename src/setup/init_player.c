#include "cub3d.h"

static void	set_player_direction(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
	{
		game->player->direction_x = 0.0;
		game->player->direction_y = -1.0;
		game->player->angle_x = 0.707;
		game->player->angle_y = 0.0;
		if (c == 'S')
		{
			game->player->direction_y = 1.0;
			game->player->angle_x = -0.707;
		}
	}
	if (c == 'E' || c == 'W')
	{
		game->player->direction_x = -1.0;
		game->player->direction_y = 0.0;
		game->player->angle_x = 0.0;
		game->player->angle_y = -0.707;
		if (c == 'E')
		{
			game->player->direction_x = 1.0;
			game->player->angle_y = 0.707;
		}
	}
}

static void	extract_player_info(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_info.map[y])
	{
		x = 0;
		while (game->map_info.map[y][x])
		{
			if (ft_strchr("NSWE", game->map_info.map[y][x]))
			{
				game->player->position_x = (double)x + 0.5;
				game->player->position_y = (double)y + 0.5;
				set_player_direction(game, game->map_info.map[y][x]);
				game->map_info.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	extract_player_info(game);
	game->player->move_speed = 0.05;
	game->player->rotation_speed = 0.05;
}
