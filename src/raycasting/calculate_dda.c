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
		dda->side_distance_x = (game->player->position_x
				- dda->collision_grid_x) * dda->delta_distance_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_distance_x = (dda->collision_grid_x + 1.0
				- game->player->position_x) * dda->delta_distance_x;
	}
	if (dda->ray_direction_y < 0)
	{
		dda->step_y = -1;
		dda->side_distance_y = (game->player->position_y
				- dda->collision_grid_y) * dda->delta_distance_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_distance_y = (dda->collision_grid_y + 1.0
				- game->player->position_y) * dda->delta_distance_y;
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
	dda->delta_distance_x = fabs(1 / dda->ray_direction_x);
	dda->delta_distance_y = fabs(1 / dda->ray_direction_y);
	calculate_direction_to_step(game, dda);
}

bool	calculate_collision_grid(t_game *game, t_dda *dda)
{
	bool	did_ray_hit_wall;
	bool	is_y_collision;

	did_ray_hit_wall = false;
	while (!did_ray_hit_wall)
	{
		if (dda->side_distance_x < dda->side_distance_y)
		{
			dda->side_distance_x += dda->delta_distance_x;
			dda->collision_grid_x += dda->step_x;
			is_y_collision = false;
		}
		else
		{
			dda->side_distance_y += dda->delta_distance_y;
			dda->collision_grid_y += dda->step_y;
			is_y_collision = true;
		}
		if (game->map_info.map
			[dda->collision_grid_y][dda->collision_grid_x] == '1')
			did_ray_hit_wall = true;
	}
	return (is_y_collision);
}
