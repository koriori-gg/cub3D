#include "cub3d.h"

double	calculate_camera_location(int x, int wid)
{
	double	camera_x;

	camera_x = 2 * x / (double)wid - 1;
	return (camera_x);
}

static void	calculate_direction_to_step(t_game *game, t_dda *dda)
{
	if (dda->ray_direction_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x
			= (game->player->position_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x
			= (dda->map_x + 1.0 - game->player->position_x) * dda->delta_dist_x;
	}
	if (dda->ray_direction_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y
			= (game->player->position_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y
			= (dda->map_y + 1.0 - game->player->position_y) * dda->delta_dist_y;
	}
}

void	prepare_dda(t_game *game, t_dda *dda, int x)
{
	dda->ray_direction_x = game->player->direction_x
		+ game->player->plane_x * calculate_camera_location(x, width);
	dda->ray_direction_y = game->player->direction_y
		+ game->player->plane_y * calculate_camera_location(x, width);
	dda->map_x = (int)game->player->position_x;
	dda->map_y = (int)game->player->position_y;
	dda->delta_dist_x = fabs(1 / dda->ray_direction_x);
	dda->delta_dist_y = fabs(1 / dda->ray_direction_y);
	calculate_direction_to_step(game, dda);
}

int	calculate_dda(t_game *game, t_dda *dda)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			side = 1;
		}
		if (game->map_info.map[dda->map_y][dda->map_x] != '0')
			hit = 1;
	}
	return (side);
}
