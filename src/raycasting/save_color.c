#include "cub3d.h"

static int	calculate_texture_x(t_game *game, t_dda *dda)
{
	double	wall_x;
	int		texture_x;

	if (dda->is_y_collision == 0)
		wall_x = game->player->position_y
			+ dda->perpendicular_distance * dda->ray_direction_y;
	else
		wall_x = game->player->position_x
			+ dda->perpendicular_distance * dda->ray_direction_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if (dda->is_y_collision == 0 && dda->ray_direction_x > 0)
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	if (dda->is_y_collision == 1 && dda->ray_direction_y < 0)
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	return (texture_x);
}

static int	hit_wall_direction(t_dda *dda)
{
	if (dda->is_y_collision && dda->step_y == -1)
		return (0);
	if (dda->is_y_collision && dda->step_y == 1)
		return (1);
	if (!dda->is_y_collision && dda->step_x == -1)
		return (2);
	if (!dda->is_y_collision && dda->step_x == 1)
		return (3);
	return (0);
}

void	save_color(t_game *game, t_dda *dda, t_draw *draw, int x)
{
	int	y;
	int	color;
	int	texture_y;

	draw->texture_num = hit_wall_direction(dda);
	draw->texture_x = calculate_texture_x(game, dda);
	draw->step = 1.0 * TEXTURE_HEIGHT / draw->line_height;
	draw->texture_position = (draw->draw_start - HEIGHT / 2
			+ draw->line_height / 2) * draw->step;
	y = draw->draw_start;
	save_ceiling(game, draw, x);
	while (y < draw->draw_end)
	{
		texture_y = (int)draw->texture_position & (TEXTURE_HEIGHT - 1);
		draw->texture_position += draw->step;
		color = game->texture
		[draw->texture_num][TEXTURE_HEIGHT * texture_y - draw->texture_x];
		if (dda->is_y_collision == 1)
			color = (color >> 1) & 8355711;
		game->buf[y][x] = color;
		game->re_buf = 1;
		y++;
	}
	save_floor(game, draw, x);
}
