#include "cub3d.h"

void	draw_vertical_line(t_game *game, int x, int top, int bottom, int color)
{
	int	y;

	y = top;
	while (y <= bottom)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		y++;
	}
}

static t_map	*move_map(t_map *map, int num)
{
	while (map->y > num && map->prev)
		map = map->prev;
	while (map->y < num && map->next)
		map = map->next;
	return (map);
}

int get_color(t_game *game, int map_x, int map_y, int side)
{
	int color;

	if (game->world_map[map_y][map_x] == '1')
		color = RGB_RED;
	else if (game->world_map[map_y][map_x] == '2')
		color = RGB_GREEN;
	else if (game->world_map[map_y][map_x] == '3')
		color = RGB_BLUE;
	else if (game->world_map[map_y][map_x] == '4')
		color = RGB_WHITE;
	else
		color = RGB_YELLOW;
	if (side == 1)
		color = color / 2;
	return (color);
}

double calculate_camera_location(int x, int wid)
{
	double camera_x;

	camera_x = 2 * x / (double)wid - 1;
	return (camera_x);
}

int	calculate_draw_end(int hei, int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + hei / 2;
	if(draw_end >= hei)
		draw_end = hei - 1;
	return (draw_end);
}

int	 calculate_draw_start(int hei, int line_height)
{
	int draw_start;

	draw_start =  hei / 2 - line_height / 2;
	if(draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

void	prepare_dda(t_game *game, t_dda *dda, int x)
{
		dda->ray_direction_x = game->player->direction_x + game->player->plane_x * calculate_camera_location(x, width);
		dda->ray_direction_y = game->player->direction_y + game->player->plane_y * calculate_camera_location(x, width);
		dda->map_x = (int)game->player->position_x;
		dda->map_y = (int)game->player->position_y;
		dda->delta_dist_x = fabs(1 / dda->ray_direction_x);//fabs 浮動小数点ありの絶対値
		dda->delta_dist_y = fabs(1 / dda->ray_direction_y);
		if (dda->ray_direction_x < 0)
		{
			dda->step_x = -1;
			dda->side_dist_x = (game->player->position_x - dda->map_x) * dda->delta_dist_x;
		}
		else
		{
			dda->step_x = 1;
			dda->side_dist_x = (dda->map_x + 1.0 - game->player->position_x) * dda->delta_dist_x;
		}
		if (dda->ray_direction_y < 0)
		{
			dda->step_y = -1;
			dda->side_dist_y = (game->player->position_y - dda->map_y) *dda->delta_dist_y;
		}
		else
		{
			dda->step_y = 1;
			dda->side_dist_y = (dda->map_y + 1.0 - game->player->position_y) * dda->delta_dist_y;
		}
}

int	calculate_dda(t_game *game, t_dda *dda)
{
	int hit; //was there a wall hit?
	int side; //was a NS or a EW wall hit?

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
		if (game->world_map[dda->map_x][dda->map_y] != '0')
			hit = 1;
	}
	return (side);
}

int char_to_int(char s)
{
	if (s == '0')
		return (0);
	if (s == '1')
		return (1);
	if (s == '2')
		return (2);
	if (s == '3')
		return (3);
	if (s == '4')
		return (4);
	if (s == '5')
		return (5);
	if (s == '6')
		return (6);
	if (s == '7')
		return (7);
	if (s == '8')
		return (8);
	if (s == '9')
		return (9);
}

void	prepare_map_draw(t_draw	*draw, double perp_wall_dist)
{
	draw->line_height = (int)(height / perp_wall_dist);
	draw->draw_start = calculate_draw_start(height, draw->line_height);
	draw->draw_end = calculate_draw_end(height, draw->line_height);
}

int calculate_texture_x(t_game *game,t_dda dda, int side)
{
	double wall_x;
	int tex_x;

	if (side == 0)
		wall_x = game->player->position_y + dda.perp_wall_dist * dda.ray_direction_y;
	else
		wall_x = game->player->position_x + dda.perp_wall_dist * dda.ray_direction_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex_width);
	if (side == 0 && dda.ray_direction_x > 0)
		tex_x = tex_width - tex_x - 1;
	if (side == 1 && dda.ray_direction_y < 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

void	save_color(t_game *game, t_dda dda, t_draw draw, int x)
{
		draw.tex_num = char_to_int(game->world_map[dda.map_x][dda.map_y]);//もうちょっといい変換方法ありそう
		draw.tex_x = calculate_texture_x(game, dda, dda.side);
		draw.step = 1.0 * tex_height / draw.line_height;
		draw.tex_position = (draw.draw_start - height / 2 + draw.line_height / 2) * draw.step;
		int y;
		y = draw.draw_start;
		while (y < draw.draw_end)
		{
			int tex_y = (int)draw.tex_position & (tex_height - 1);
			draw.tex_position += draw.step;
			int color = game->texture[draw.tex_num][tex_height * tex_y + draw.tex_x];
			if (dda.side == 1)
				color = (color >> 1) & 8355711;
			game->buf[y][x] = color;
			game->re_buf = 1;
			y++;
		}
}

void	calculate(t_game *game)
{
	int		x;
	t_dda	dda;
	t_draw	draw;
	double	perp_wall_dist;
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

		save_color(game, dda, draw, x);
		x++;
	}
}
