#include "cub3d.h"

void	set_player_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		game->player->direction_x = 0.0;
		game->player->direction_y = -1.0;
		game->player->angle_x = 0.707;
		game->player->angle_y = 0.0;

	}
	if (c == 'S')
	{
		game->player->direction_x = 0.0;
		game->player->direction_y = 1.0;
		game->player->angle_x = -0.707;
		game->player->angle_y = 0.0;
	}
	if (c == 'E')
	{
		game->player->direction_x = 1.0;
		game->player->direction_y = 0.0;
		game->player->angle_x = 0.0;
		game->player->angle_y = 0.707;
	}
	if (c == 'W')
	{
		game->player->direction_x = -1.0;
		game->player->direction_y = 0.0;
		game->player->angle_x = 0.0;
		game->player->angle_y = -0.707;
	}
}

void	extract_player_info(t_game *game)
{
	int	y;
	int x;

	y = 0;
	while (game->map_info.map[y])
	{
		x = 0;
		while (game->map_info.map[y][x])
		{
			if (ft_strchr("NSWE", game->map_info.map[y][x]))
			{
				game->player->position_x = (double)x + 0.5;
				game->player->position_y = (double)y + 0.5;
				set_player_direction(game, game->map_info.map[y][x]);
				game->map_info.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	extract_player_info(game);
	game->player->move_speed = 0.05;
	game->player->rotation_speed = 0.05;
}

static void	init_map_info(t_map_info *map_info)
{
	map_info->north_texture = NULL;
	map_info->south_texture = NULL;
	map_info->west_texture = NULL;
	map_info->east_texture = NULL;
	map_info->floor_color = NULL;
	map_info->ceiling_color = NULL;
	map_info->map = NULL;
}

static int	get_minimap_size(t_game *game)
{
	char	**map;
	int		max_length;
	int		i;

	map = game->map_info.map;
	max_length = 0;
	i = 0;
	while (map[i])
	{
		if (max_length < (int)ft_strlen(map[i]))
			max_length = ft_strlen(map[i]) - 1;
		i++;
	}
	return (max_length * game->minimap.img_width);
}

void	init_game(t_game *game, int fd)
{
	init_map_info(&game->map_info);
	game->map_info = get_map_info(fd);
	print_info(game->map_info);
	init_player(game);
	game->mlx = mlx_init();
	init_minimap(game);
	init_texture(game);
	game->win = mlx_new_window(game->mlx, WIDTH
			+ get_minimap_size(game), HEIGHT, "cub3D");
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_line, &game->img.endian);
}
