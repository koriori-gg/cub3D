#include "cub3d.h"

void	calculate(t_game *game)
{
	int		x;
	t_dda	dda;
	t_draw	draw;
	int 	tex_x;

	x = 0;
	while (x < width)
	{
		prepare_dda(game, &dda, x);
		dda.side = calculate_dda(game, &dda);
		if (dda.side == 0)
			dda.perp_wall_dist = (dda.map_x - game->player->position_x + (1 - dda.step_x) / 2) / dda.ray_direction_x;
		else
			dda.perp_wall_dist = (dda.map_y - game->player->position_y + (1 - dda.step_y) / 2) / dda.ray_direction_y;
		prepare_map_draw(&draw, dda.perp_wall_dist);
		save_color(game, &dda, &draw, x);
		x++;
	}
}
