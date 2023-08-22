#include "cub3d.h"

void	calculate_field_of_view(t_game *game)
{
	int		x;
	t_dda	dda;
	t_draw	draw;

	x = 0;
	while (x < WIDTH)
	{
		prepare_dda(game, &dda, x);
		dda.side = calculate_dda(game, &dda);
		if (dda.side == 0)
			dda.perpendicular_distance = (dda.map_x - game->player->position_x
					+ (1 - dda.step_x) / 2) / dda.ray_direction_x;
		else
			dda.perpendicular_distance = (dda.map_y - game->player->position_y
					+ (1 - dda.step_y) / 2) / dda.ray_direction_y;
		prepare_map_draw(&draw, dda.perpendicular_distance);
		save_color(game, &dda, &draw, x);
		x++;
	}
}
