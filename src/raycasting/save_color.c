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

void	prepare_map_draw(t_draw	*draw, double perp_wall_dist)
{
	draw->line_height = (int)(height / perp_wall_dist);
	draw->draw_start = calculate_draw_start(height, draw->line_height);
	draw->draw_end = calculate_draw_end(height, draw->line_height);
}

int	calculate_texture_x(t_game *game, t_dda *dda)
{
	double	wall_x;
	int		tex_x;

	if (dda->side == 0)
		wall_x = game->player->position_y
			+ dda->perp_wall_dist * dda->ray_direction_y;
	else
		wall_x = game->player->position_x
			+ dda->perp_wall_dist * dda->ray_direction_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex_width);
	if (dda->side == 0 && dda->ray_direction_x > 0)
		tex_x = tex_width - tex_x - 1;
	if (dda->side == 1 && dda->ray_direction_y < 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

void	save_color(t_game *game, t_dda *dda, t_draw *draw, int x)
{
	int	y;
	int	color;
	int	tex_y;

	draw->tex_num = char_to_int(game->map_info.map[dda->map_y][dda->map_x]);
	draw->tex_x = calculate_texture_x(game, dda);
	draw->step = 1.0 * tex_height / draw->line_height;
	draw->tex_position = (draw->draw_start - height / 2
			+ draw->line_height / 2) * draw->step;
	y = draw->draw_start;
	save_ceiling(game, draw, x);
	while (y < draw->draw_end)
	{
		tex_y = (int)draw->tex_position & (tex_height - 1);
		draw->tex_position += draw->step;
		color = game->texture[draw->tex_num][tex_height * tex_y + draw->tex_x];
		if (dda->side == 1)
			color = (color >> 1) & 8355711;
		game->buf[y][x] = color;
		game->re_buf = 1;
		y++;
	}
	save_floor(game, draw, x);
}
