#include "cub3d.h"

double	calculate_camera_location(int x, int width)
{
	double	camera_x;

	camera_x = 2 * x / (double)width - 1;
	return (camera_x);
}

static void	calculate_direction_to_step(t_game *game, t_dda *dda)
{
	if (dda->ray_direction_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x
			= (game->player->position_x - dda->collision_grid_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x
			= (dda->collision_grid_x + 1.0 - game->player->position_x) * dda->delta_dist_x;
	}
	if (dda->ray_direction_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y
			= (game->player->position_y - dda->collision_grid_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y
			= (dda->collision_grid_y + 1.0 - game->player->position_y) * dda->delta_dist_y;
	}
}

void	prepare_calculate_collision_grid(t_game *game, t_dda *dda, int x)
{
	dda->ray_direction_x = game->player->direction_x
		+ game->player->angle_x * calculate_camera_location(x, WIDTH);
	dda->ray_direction_y = game->player->direction_y
		+ game->player->angle_y * calculate_camera_location(x, WIDTH);
	dda->collision_grid_x = (int)game->player->position_x;
	dda->collision_grid_y = (int)game->player->position_y;
	dda->delta_dist_x = fabs(1 / dda->ray_direction_x);
	dda->delta_dist_y = fabs(1 / dda->ray_direction_y);
	calculate_direction_to_step(game, dda);
}

bool	calculate_collision_grid(t_game *game, t_dda *dda)
{
	bool	hit;
	bool	is_y_collision;

	hit = false;
	while (!hit)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->collision_grid_x += dda->step_x;
			is_y_collision = false;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->collision_grid_y += dda->step_y;
			is_y_collision = true;
		}
		if (game->map_info.map[dda->collision_grid_y][dda->collision_grid_x] != '0')
			hit = true;
	}
	return (is_y_collision);
}
