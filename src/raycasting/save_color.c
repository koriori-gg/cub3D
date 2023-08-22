#include "cub3d.h"

int	calculate_draw_end(int window_height, int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + window_height / 2;
	if (draw_end >= window_height)
		draw_end = window_height - 1;
	return (draw_end);
}

int	calculate_draw_start(int window_height, int line_height)
{
	int	draw_start;

	draw_start = window_height / 2 - line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

void	prepare_map_draw(t_draw	*draw, double perpendicular_distance)
{
	draw->line_height = (int)(HEIGHT / perpendicular_distance);
	draw->draw_start = calculate_draw_start(HEIGHT, draw->line_height);
	draw->draw_end = calculate_draw_end(HEIGHT, draw->line_height);
}

int	calculate_texture_x(t_game *game, t_dda *dda)
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

void	save_color(t_game *game, t_dda *dda, t_draw *draw, int x)
{
	int	y;
	int	color;
	int	texture_y;

	draw->texture_num = game->map_info.map
	[dda->collision_grid_y][dda->collision_grid_x] - 48;
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
		[draw->texture_num][TEXTURE_HEIGHT * texture_y + draw->texture_x];
		if (dda->is_y_collision == 1)
			color = (color >> 1) & 8355711;
		game->buf[y][x] = color;
		game->re_buf = 1;
		y++;
	}
	save_floor(game, draw, x);
}
