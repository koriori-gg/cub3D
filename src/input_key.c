#include "cub3d.h"

void	move(int keycode, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		if (game->map_info.map[(int)(player->position_y)]
			[(int)(player->position_x
				+ player->direction_x * player->move_speed)] == '0')
			player->position_x += player->direction_x * player->move_speed;
		if (game->map_info.map[(int)(player->position_y + player->direction_y
				* player->move_speed)][(int)(player->position_x)] == '0')
			player->position_y += player->direction_y * player->move_speed;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		if (game->map_info.map[(int)(player->position_y)]
			[(int)(player->position_x
				- player->direction_x * player->move_speed)] == '0')
			player->position_x -= player->direction_x * player->move_speed;
		if (game->map_info.map[(int)(player->position_y - player->direction_y
				* player->move_speed)][(int)(player->position_x)] == '0')
			player->position_y -= player->direction_y * player->move_speed;
	}
}

void	change_direction_of_movement(int keycode, t_game *game)
{
	double		old_direction_x;
	double		old_plane_x;
	t_player	*player;

	player = game->player;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		old_direction_x = player->direction_x;
		player->direction_x = player->direction_x * cos(player->rot_speed)
			- player->direction_y * sin(player->rot_speed);
		player->direction_y = old_direction_x * sin(player->rot_speed)
			+ player->direction_y * cos(player->rot_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->rot_speed)
			- player->plane_y * sin(player->rot_speed);
		player->plane_y = old_plane_x * sin(player->rot_speed)
			+ player->plane_y * cos(player->rot_speed);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		old_direction_x = player->direction_x;
		player->direction_x = player->direction_x * cos(-player->rot_speed)
			- player->direction_y * sin(-player->rot_speed);
		player->direction_y = old_direction_x * sin(-player->rot_speed)
			+ player->direction_y * cos(-player->rot_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-player->rot_speed)
			- player->plane_y * sin(-player->rot_speed);
		player->plane_y = old_plane_x * sin(-player->rot_speed)
			+ player->plane_y * cos(-player->rot_speed);
	}
}

int	input_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	move(keycode, game);
	change_direction_of_movement(keycode, game);
	return (0);
}
