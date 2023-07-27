#include "cub3d.h"

void	draw_vertical_line(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
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

void	calculate(t_game *game)
{
	int	x;
	t_map *map;

	map = game->map_info->map;
	x = 0;
	while (x < width)
	{
		double camera_x = 2 * x / (double)width - 1;
		double ray_direction_x = game->player->direction_x + game->player->plane_x * camera_x;
		double ray_direction_y = game->player->direction_y + game->player->plane_y * camera_x;

		int map_x = (int)game->player->position_x;
		int map_y = (int)game->player->position_y;
		// map = move_map(map, map_y);
		//length of ray from current position to next x or y-side
		double side_dest_x;
		double side_dest_y;

		 //length of ray from one x or y-side to next x or y-side
		double delta_dist_x = fabs(1 / ray_direction_x); //fabs 浮動小数点ありの絶対値
		double delta_dist_y = fabs(1 / ray_direction_y);
		double perp_wall_dist;

		//what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (ray_direction_x < 0)
		{
			step_x = -1;
			side_dest_x = (game->player->position_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dest_x = (map_x + 1.0 - game->player->position_x) * delta_dist_x;
		}
		if (ray_direction_y < 0)
		{
			step_y = -1;
			side_dest_y = (game->player->position_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dest_y = (map_y + 1.0 - game->player->position_y) * delta_dist_y;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (side_dest_x < side_dest_y)
			{
				side_dest_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dest_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			map = move_map(map, map_y);
			//Check if ray has hit a wall
			// if (worldMap[map_x][map_y] > 0)
			if (map->row[map_x] > 0)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - game->player->position_x + (1 - step_x) / 2) / ray_direction_x;
		else
			perp_wall_dist = (map_y - game->player->position_y + (1 - step_y) / 2) / ray_direction_y;

		//Calculate height of line to draw on screen
		int line_height = (int)(height / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + height / 2;
		if(draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + height / 2;
		if(draw_end >= height)
			draw_end = height - 1;

		int	color;
		map = move_map(map, map_y);
		// if (worldMap[map_y][map_x] == 1)
		if (map->row[map_x] == 1)
			color = 0xFF0000;
		// else if (worldMap[map_y][map_x] == 2)
		else if (map->row[map_x] == 2)
			color = 0x00FF00;
		// else if (worldMap[map_y][map_x] == 3)
		else if (map->row[map_x] == 3)
			color = 0x0000FF;
		// else if (worldMap[map_y][map_x] == 4)
		else if (map->row[map_x] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;

		if (side == 1)
			color = color / 2;

		draw_vertical_line(game, x, draw_start, draw_end, color);

		x++;
	}
}