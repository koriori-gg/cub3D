#include "cub3d.h"

static void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	//temp
	game->player->position_x = 12.0;//本来はmapから読み取る必要あり
	game->player->position_y = 5.0;
	game->player->direction_x = -1.0;
	game->player->direction_y = 0.0;
	game->player->plane_x = 0.0;
	game->player->plane_y = 0.66;
	game->player->move_speed = 0.05;
	game->player->rot_speed = 0.05;
	// game->re_buf = 0;
	// game->buf = (int **)malloc(sizeof(int *) * height);
	// for (int i = 0; i < height; i++)
	// {
	// 	game->buf[i] = (int *)malloc(sizeof(int) * width);
	// }

	// for (int i = 0; i < height; i++)
	// {
	// 	for (int j = 0; j < width; j++)
	// 	{
	// 		game->buf[i][j] = 0;
	// 	}
	// }

	// for (int i = 0; i < 8; i++)
	// {
	// 	for (int j = 0; j < tex_height * tex_width; j++)
	// 	{
	// 		game->texture[i][j] = 0;
	// 	}
	// }

	// for (int x = 0; x < tex_width; x++)
	// {
	// 	for (int y = 0; y < tex_height; y++)
	// 	{
	// 		int xorcolor = (x * 256 / tex_width) ^ (y * 256 / tex_height);
	// 		int ycolor = y * 256 / tex_height;
	// 		int xycolor = y * 128 / tex_height + x * 128 / tex_width;
	// 		game->texture[0][tex_width * y + x] = 65536 * 254 * (x != y && x != tex_width - y); //flat red texture with black cross
	// 		game->texture[1][tex_width * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
	// 		game->texture[2][tex_width * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
	// 		game->texture[3][tex_width * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
	// 		game->texture[4][tex_width * y + x] = 256 * xorcolor; //xor green
	// 		game->texture[5][tex_width * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
	// 		game->texture[6][tex_width * y + x] = 65536 * ycolor; //red gradient
	// 		game->texture[7][tex_width * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
	// 	}
	// }
}

char	**map_to_char(t_map *map)
{
	int		size;
	int		i;
	char	**ret;

	size = ft_mapsize(map);
	ret = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!ret)
		error_exit(MALLOC_ERROR);
	i = 0;
	while (map)
	{
		ret[i] = ft_strdup(map->row);
		i++;
		map = map->next;
	}
	ret[i] = 0;
	return (ret);
}


static void	*ft_xpm_to_image(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin("textures/4/", str);//path error
	img = mlx_xpm_file_to_image(game->mlx, path, &game->img_width,
			&game->img_height);
	free(path);
	if (!img)
		error_exit(IMAGE_ERROR);
	return (img);
}

void	init_asset(t_game *game)
{
	game->tile_img[0] = ft_xpm_to_image(game, "zero.xpm");
	game->tile_img[1] = ft_xpm_to_image(game, "one.xpm");
	game->tile_img[2] = ft_xpm_to_image(game, "player.xpm");
}

void	init_struct(t_game *game, char **argv)
{
	init_player(game);
	game->map_info = init_mapinfo(argv);//initのやり方統一した方がいい??
	print_map_info(game->map_info);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 1000, "cub3D");//map + minimap
	// mlx_pixel_put(game->mlx, game->win, 10, 20, 4169e1);
	game->world_map = map_to_char(game->map_info->map);
	print_argv(game->world_map);
	game->img_width = 5;
	game->img_height = 5;
	init_asset(game);
	// game->img.img = mlx_new_image(game->mlx, width, height);
	// game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
