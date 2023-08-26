#include "cub3d.h"

static void	move_left_and_right(int keycode, t_game *game)
{
	t_player	*player;

	player = game->player;
	if (keycode == KEY_D)
	{
		if (game->map_info.map[(int)(player->position_y)]
			[(int)(player->position_x
				+ player->angle_x * player->move_speed)] == '0')
			player->position_x += player->angle_x * player->move_speed;
		if (game->map_info.map[(int)(player->position_y + player->angle_y
				* player->move_speed)][(int)(player->position_x)] == '0')
			player->position_y += player->angle_y * player->move_speed;
	}
	else if (keycode == KEY_A)
	{
		if (game->map_info.map[(int)(player->position_y)]
			[(int)(player->position_x
				- player->angle_x * player->move_speed)] == '0')
			player->position_x -= player->angle_x * player->move_speed;
		if (game->map_info.map[(int)(player->position_y - player->angle_y
				* player->move_speed)][(int)(player->position_x)] == '0')
			player->position_y -= player->angle_y * player->move_speed;
	}
}

static void	move_up_and_down(int keycode, t_game *game)
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

static void	turn_right(int keycode, t_game *game)
{
	t_player	*player;
	double		old_direction_x;
	double		old_angle_x;

	player = game->player;
	if (keycode == KEY_RIGHT)
	{
		old_direction_x = player->direction_x;
		player->direction_x = player->direction_x * cos(player->rotation_speed)
			- player->direction_y * sin(player->rotation_speed);
		player->direction_y = old_direction_x * sin(player->rotation_speed)
			+ player->direction_y * cos(player->rotation_speed);
		old_angle_x = player->angle_x;
		player->angle_x = player->angle_x * cos(player->rotation_speed)
			- player->angle_y * sin(player->rotation_speed);
		player->angle_y = old_angle_x * sin(player->rotation_speed)
			+ player->angle_y * cos(player->rotation_speed);
	}
}

static void	turn_left(int keycode, t_game *game)
{
	t_player	*player;
	double		old_direction_x;
	double		old_angle_x;

	player = game->player;
	if (keycode == KEY_LEFT)
	{
		old_direction_x = player->direction_x;
		player->direction_x = player->direction_x * cos(-player->rotation_speed)
			- player->direction_y * sin(-player->rotation_speed);
		player->direction_y = old_direction_x * sin(-player->rotation_speed)
			+ player->direction_y * cos(-player->rotation_speed);
		old_angle_x = player->angle_x;
		player->angle_x = player->angle_x * cos(-player->rotation_speed)
			- player->angle_y * sin(-player->rotation_speed);
		player->angle_y = old_angle_x * sin(-player->rotation_speed)
			+ player->angle_y * cos(-player->rotation_speed);
	}
}

int	input_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	move_up_and_down(keycode, game);
	move_left_and_right(keycode, game);
	turn_right(keycode, game);
	turn_left(keycode, game);
	return (0);
}
