#include "cub3d.h"

// __attribute__((destructor))
// void    destructor(void)
// {
//     system("leaks cub3d");
// }

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//TODO: add free
	exit(0);
}

void	update_pre_position(int keycode, t_game *game)
{
	if (keycode == KEY_UP || keycode == KEY_W || keycode == KEY_DOWN || keycode == KEY_S
		|| keycode == KEY_RIGHT || keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_A)
		game->player->pre_position_x = game->player->position_x;
		game->player->pre_position_y = game->player->position_y;
}

void	change_map(t_game *game, t_map *map, int map_x, int map_y)
{
	char	temp;
	int		pre_map_x;
	int		pre_map_y;

	temp = game->world_map[map_y][map_x];
	pre_map_x = (int)game->player->pre_position_x;
	pre_map_y = (int)game->player->pre_position_y;
	while (map->y < map_y)
		map = map->next;
	while (map->y < pre_map_y)
		map = map->next;
	if (map->row[map_x] == 0)
	{
		temp = map->row[map_x];
		map->row[map_x] = map->row[pre_map_x];
		map->row[pre_map_x] = temp;
	}
}

void	change_worldmap(int map_x, int map_y, t_game *game)
{
	char	temp;
	int		pre_map_x;
	int		pre_map_y;

	if (game->world_map[map_y][map_x] == 0)
	{
		temp = game->world_map[map_y][map_x];
		pre_map_x = (int)game->player->pre_position_x;
		pre_map_y = (int)game->player->pre_position_y;
		game->world_map[map_y][map_x] = game->world_map[pre_map_y][pre_map_x];
		game->world_map[pre_map_y][pre_map_x] = temp;
	}
}

void	update_map(t_game *game)
{
	int	map_x;
	int map_y;

	map_x = (int)game->player->position_x;
	map_y = (int)game->player->position_y;
	change_map(game, game->map_info->map, map_x, map_y);
	change_worldmap(map_x, map_y, game);
}

int input_key(int keycode, t_game *game)
{
	printf("before position :x %lf y %lf + %lf\n", game->player->position_x, game->player->position_y, game->player->direction_x * game->player->move_speed);
	printf("before direction:x %lf y %lf\n", game->player->direction_x, game->player->direction_y);
	if (keycode == KEY_ESC)
		close_game(game);
	update_pre_position(keycode, game);
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		printf("go\n");
		printf("int    position :x %d y %d\n", (int)(game->player->position_x + game->player->direction_x * game->player->move_speed), (int)game->player->position_y);
		if (game->world_map[(int)(game->player->position_y)][(int)(game->player->position_x + game->player->direction_x * game->player->move_speed)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_y)][(int)(game->player->position_x + game->player->direction_x * game->player->move_speed)]) == 0)
			game->player->position_x += game->player->direction_x * game->player->move_speed;
		if (game->world_map[(int)(game->player->position_y + game->player->direction_y * game->player->move_speed)][(int)(game->player->position_x)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_y + game->player->direction_y * game->player->move_speed)][(int)(game->player->position_x)]) == 0)
			game->player->position_y += game->player->direction_y * game->player->move_speed;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		printf("back\n");
		if (game->world_map[(int)(game->player->position_y)][(int)(game->player->position_x - game->player->direction_x * game->player->move_speed)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_y)][(int)(game->player->position_x + game->player->direction_x * game->player->move_speed)]) == 0)
			game->player->position_x -= game->player->direction_x * game->player->move_speed;
		if (game->world_map[(int)(game->player->position_y - game->player->direction_y * game->player->move_speed)][(int)(game->player->position_x)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_y - game->player->direction_y * game->player->move_speed)][(int)(game->player->position_x)]) == 0)
			game->player->position_y -= game->player->direction_y * game->player->move_speed;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		printf("right\n");
		double old_direction_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * cos(-game->player->rot_speed) - game->player->direction_y * sin(-game->player->rot_speed);
		game->player->direction_y = old_direction_x * sin(-game->player->rot_speed) + game->player->direction_y * cos(-game->player->rot_speed);
		double old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(-game->player->rot_speed) - game->player->plane_y * sin(-game->player->rot_speed);
		game->player->plane_y = old_plane_x * sin(-game->player->rot_speed) + game->player->plane_y * cos(-game->player->rot_speed);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		printf("left\n");
		double old_direction_x = game->player->direction_x;
		game->player->direction_x = game->player->direction_x * cos(game->player->rot_speed) - game->player->direction_y * sin(game->player->rot_speed);
		game->player->direction_y = old_direction_x * sin(game->player->rot_speed) + game->player->direction_y * cos(game->player->rot_speed);
		double old_plane_x = game->player->plane_x;
		game->player->plane_x = game->player->plane_x * cos(game->player->rot_speed) - game->player->plane_y * sin(game->player->rot_speed);
		game->player->plane_y = old_plane_x * sin(game->player->rot_speed) + game->player->plane_y * cos(game->player->rot_speed);
	}
	printf("after  position :x %lf y %lf\n", game->player->position_x, game->player->position_y);
	printf("after  direction:x %lf y %lf\n", game->player->direction_x, game->player->direction_y);
	printf("-------------\n");
	update_map(game);
	return (0);
}

int	main_loop(t_game *game)
{
	draw_map(game);
	calculate(game);
	draw(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	printf("argc : %d\n", argc);
	// validate_argument(argc, argv);
	init_struct(&game, argv);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L<<0, &input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
}
