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
void	prepare_dda(t_game *game, t_dda *dda, double ray_direction_x, double ray_direction_y)
{
		dda->map_x = (int)game->player->position_x;
		dda->map_y = (int)game->player->position_y;
		dda->delta_dist_x = fabs(1 / ray_direction_x);//fabs 浮動小数点ありの絶対値
		dda->delta_dist_y = fabs(1 / ray_direction_y);
		if (ray_direction_x < 0)
		{
			dda->step_x = -1;
			dda->side_dist_x = (game->player->position_x - dda->map_x) * dda->delta_dist_x;//ここ0になってしまっている　いいんかも？？
		}
		else
		{
			dda->step_x = 1;
			dda->side_dist_x = (dda->map_x + 1.0 - game->player->position_x) * dda->delta_dist_x;
		}
		if (ray_direction_y < 0)
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
	// printf("map %d %d step %d %d\n", dda->map_x, dda->map_y, dda->step_x, dda->step_y);
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

void	calculate(t_game *game)
{
	int	x;
	t_dda	dda;

	x = 0;
	while (x < width)
	{
		double ray_direction_x = game->player->direction_x + game->player->plane_x * calculate_camera_location(x, width);
		double ray_direction_y = game->player->direction_y + game->player->plane_y * calculate_camera_location(x, width);
		prepare_dda(game, &dda, ray_direction_x, ray_direction_y);
		// printf("delta %lf %lf side %lf %lf\n", dda.delta_dist_x, dda.delta_dist_y, dda.side_dist_x, dda.side_dist_y);
		int side;
		side = calculate_dda(game, &dda);
		// printf("map %d %d\n", dda.map_x, dda.map_y);
		double perp_wall_dist;
		if (side == 0)
			perp_wall_dist = (dda.map_x - game->player->position_x + (1 - dda.step_x) / 2) / ray_direction_x;
		else
			perp_wall_dist = (dda.map_y - game->player->position_y + (1 - dda.step_y) / 2) / ray_direction_y;
		int line_height = (int)(height / perp_wall_dist);
		int draw_start = calculate_draw_start(height, line_height);
		int draw_end = calculate_draw_end(height, line_height);
		int	color = get_color(game, side, dda.map_x, dda.map_y);
		// printf("--- draw %d %d %d color %d map %d %d\n", x, draw_start, draw_end, color, dda.map_x, dda.map_y);
		draw_vertical_line(game, x, draw_start, draw_end, color);
		x++;
	}
}
