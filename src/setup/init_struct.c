#include "cub3d.h"

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
	validate_map(game->map_info.map);
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
