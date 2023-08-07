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

int input_key(int keycode, t_game *game)
{
	printf("before position :%lf %lf + %lf\n", game->player->position_x, game->player->position_y, game->player->direction_x * game->player->move_speed);
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
	{
		printf("go\n");
		if (game->world_map[(int)(game->player->position_x + game->player->direction_x * game->player->move_speed)][(int)(game->player->position_y)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_x + game->player->direction_x * game->player->move_speed)][(int)(game->player->position_y)]))
			game->player->position_x += game->player->direction_x * game->player->move_speed;
		if (game->world_map[(int)(game->player->position_x)][(int)(game->player->position_y + game->player->direction_y * game->player->move_speed)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_x)][(int)(game->player->position_y + game->player->direction_y * game->player->move_speed)]))
			game->player->position_y += game->player->direction_y * game->player->move_speed;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		printf("back\n");
		if (game->world_map[(int)(game->player->position_x - game->player->direction_x * game->player->move_speed)][(int)(game->player->position_y)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_x + game->player->direction_x * game->player->move_speed)][(int)(game->player->position_y)]))
			game->player->position_x -= game->player->direction_x * game->player->move_speed;
		if (game->world_map[(int)(game->player->position_x)][(int)(game->player->position_y - game->player->direction_y * game->player->move_speed)] == 0 || ft_strchr("NSWE", game->world_map[(int)(game->player->position_x)][(int)(game->player->position_y + game->player->direction_y * game->player->move_speed)]))
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
	printf("after  position :%lf %lf\n", game->player->position_x, game->player->position_y);
	// update_map(game);
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
