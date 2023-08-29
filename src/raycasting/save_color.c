#include "cub3d.h"

static int	calculate_texture_x(t_game *game, t_dda *dda)
{
	double	wall_x;
	int		texture_x;

	if (!dda->is_y_collision)
		wall_x = game->player->position_y
			+ dda->perpendicular_distance * dda->ray_direction_y;
	else
		wall_x = game->player->position_x
			+ dda->perpendicular_distance * dda->ray_direction_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (!dda->is_y_collision && dda->ray_direction_x > 0)
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	if (dda->is_y_collision && dda->ray_direction_y < 0)
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	return (texture_x);
}

static int	hit_wall_direction(t_dda *dda)
{
	if (dda->is_y_collision && dda->step_y == -1)
		return (NORTH);
	if (dda->is_y_collision && dda->step_y == 1)
		return (SOUTH);
	if (!dda->is_y_collision && dda->step_x == -1)
		return (WEST);
	if (!dda->is_y_collision && dda->step_x == 1)
		return (EAST);
	return (NORTH);
}

void	save_color(t_game *game, t_dda *dda, t_draw *draw, int x)
{
	int	y;
	int	color;
	int	texture_y;

	draw->hit_wall_texture = hit_wall_direction(dda);
	draw->texture_x = calculate_texture_x(game, dda);
	draw->step = 1.0 * TEXTURE_HEIGHT / draw->line_height;
	draw->texture_start_y = (draw->draw_start - HEIGHT / 2
			+ draw->line_height / 2) * draw->step;
	save_ceiling(game, draw, x);
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		texture_y = (int)draw->texture_start_y & (TEXTURE_HEIGHT - 1);
		draw->texture_start_y += draw->step;
		color = game->texture[draw->hit_wall_texture]
		[TEXTURE_HEIGHT * (texture_y + 1) - draw->texture_x - 1];
		game->field_of_view_pixel_color[y][x] = color;
		y++;
	}
	save_floor(game, draw, x);
}
