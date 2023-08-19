#include "cub3d.h"

static void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	game->player->position_x = 11.5;
	game->player->position_y = 22.0;
	game->player->direction_x = 0.0;
	game->player->direction_y = -1.0;
	game->player->plane_x = 0.66;
	game->player->plane_y = 0.0;
	game->player->move_speed = 0.05;
	game->player->rot_speed = 0.05;
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
	init_player(game);
	init_map_info(&game->map_info);
	game->map_info = get_map_info(fd);
	print_info(game->map_info);
	game->mlx = mlx_init();
	init_minimap(game);
	init_texture(game);
	game->win = mlx_new_window(game->mlx, width
			+ get_minimap_size(game), height, "cub3D");
	game->img.img = mlx_new_image(game->mlx, width, height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}
