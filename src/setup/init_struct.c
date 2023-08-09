#include "cub3d.h"

static void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	//temp
	game->player->position_x = 22.0;//本来はmapから読み取る必要あり
	game->player->position_y = 11.5;
	game->player->direction_x = -1.0;//本来はmapから読み取る必要あり
	game->player->direction_y = 0.0;
	game->player->plane_x = 0.0;
	game->player->plane_y = 0.66;
	game->player->move_speed = 0.05;
	game->player->rot_speed = 0.05;
}

void	load_image(t_game *game, int *texture, char *path, t_image *img)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width, &img->img_height);
	printf("hpppp\n");
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(game->mlx, img->img);
}

void	*ft_xpm_to_image2(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin("textures/", str);
	if (!path)
		error_exit(MALLOC_ERROR);
	img = mlx_xpm_file_to_image(game->mlx, path, &game->minimap.img_width,
			&game->minimap.img_height);
	free(path);
	if (!img)
		error_exit(IMAGE_ERROR);
	return (img);
}

void	load_texture(t_game *game)
{
	t_image	img;

	printf("hoge1\n");
	// game->texture[0] = ft_xpm_to_image2(game, "eagle.xpm");
	// game->texture[1] = ft_xpm_to_image2(game, "redbrick.xpm");
	// game->texture[2] = ft_xpm_to_image2(game, "purplestone.xpm");
	// game->texture[3] = ft_xpm_to_image2(game, "greystone.xpm");
	// game->texture[4] = ft_xpm_to_image2(game, "bluestone.xpm");
	// game->texture[5] = ft_xpm_to_image2(game, "mossy.xpm");
	// game->texture[6] = ft_xpm_to_image2(game, "wood.xpm");
	// game->texture[7] = ft_xpm_to_image2(game, "colorstone.xpm");
	load_image(game, game->texture[0], "textures/eagle.xpm", &img);
	load_image(game, game->texture[1], "textures/redbrick.xpm", &img);
	load_image(game, game->texture[2], "textures/purplestone.xpm", &img);
	load_image(game, game->texture[3], "textures/greystone.xpm", &img);
	load_image(game, game->texture[4], "textures/bluestone.xpm", &img);
	load_image(game, game->texture[5], "textures/mossy.xpm", &img);
	load_image(game, game->texture[6], "textures/wood.xpm", &img);
	load_image(game, game->texture[7], "textures/colorstone.xpm", &img);
	printf("hoge\n");
}

void	init_texture(t_game *game)
{
	game->re_buf = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			game->buf[i][j] = 0;
		}
	}
	if (!(game->texture = (int **)malloc(sizeof(int *) * 8)))
		return ;
	for (int i = 0; i < 8; i++)
	{
		if (!(game->texture[i] = (int *)malloc(sizeof(int) * (tex_height * tex_width))))
			return ;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < tex_height * tex_width; j++)
		{
			game->texture[i][j] = 0;
		}
	}
	load_texture(game);
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

void	init_minimap(t_game *game)
{
	game->minimap.img_width = 5;
	game->minimap.img_height = 5;
	game->minimap.tile_img[0] = ft_xpm_to_image(game, "floor.xpm");
	game->minimap.tile_img[1] = ft_xpm_to_image(game, "red.xpm");
	game->minimap.tile_img[2] = ft_xpm_to_image(game, "green.xpm");
	game->minimap.tile_img[3] = ft_xpm_to_image(game, "blue.xpm");
	game->minimap.tile_img[4] = ft_xpm_to_image(game, "white.xpm");
	game->minimap.tile_img[5] = ft_xpm_to_image(game, "yellow.xpm");
	game->minimap.tile_img[6] = ft_xpm_to_image(game, "player.xpm");
}

void	init_struct(t_game *game, char **argv)
{
	init_player(game);
	game->map_info = init_mapinfo(argv);//initのやり方統一した方がいい??
	print_map_info(game->map_info);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width * 3 / 2, height, "cub3D");//map + minimap
	game->world_map = map_to_char(game->map_info->map);
	print_argv(game->world_map);
	init_minimap(game);
	init_texture(game);
	game->img.img = mlx_new_image(game->mlx, width, height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
