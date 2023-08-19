#include "cub3d.h"

static void	init_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		error_exit(MALLOC_ERROR);
	//temp
	game->player->position_x = 11.5;//本来はmapから読み取る必要あり
	game->player->position_y = 22.0;
	game->player->direction_x = 0.0;//本来はmapから読み取る必要あり
	game->player->direction_y = -1.0;
	game->player->plane_x = 0.66;
	game->player->plane_y = 0.0;
	game->player->move_speed = 0.05;
	game->player->rot_speed = 0.05;
}

void	load_image(t_game *game, int *texture, char *path, t_image *img)
{
	int y;
	int x;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img->img);
}

void	load_texture(t_game *game)
{
	t_image	img;

	load_image(game, game->texture[0], "textures/eagle.xpm", &img);
	load_image(game, game->texture[1], "textures/redbrick.xpm", &img);
	load_image(game, game->texture[2], "textures/purplestone.xpm", &img);
	load_image(game, game->texture[3], "textures/greystone.xpm", &img);
	load_image(game, game->texture[4], "textures/bluestone.xpm", &img);
	load_image(game, game->texture[5], "textures/mossy.xpm", &img);
	load_image(game, game->texture[6], "textures/wood.xpm", &img);
	load_image(game, game->texture[7], "textures/colorstone.xpm", &img);
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
	if (!(game->texture = (int **)malloc(sizeof(int *) * 9)))
		return ;
	for (int i = 0; i < 9; i++)
	{
		if (!(game->texture[i] = (int *)malloc(sizeof(int) * (tex_height * tex_width))))
			return ;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < tex_height * tex_width; j++)
		{
			game->texture[i][j] = 0;
		}
	}
	load_texture(game);
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

static int get_minimap_size(t_game *game)
{
	char 	**map;
	int		max_length;
	int 	i;

	map = game->map_info.map;
	max_length = 0;
	i = 0;
	while (map[i])
	{
		if (max_length < (int)ft_strlen(map[i]))
			max_length = ft_strlen(map[i]);
		i++;
	}
	return (max_length * game->minimap.img_width);
}

void	init_struct(t_game *game, int fd)
{

	init_player(game);
	init_map_info(&game->map_info);
	game->map_info = get_map_info(fd);
	print_info(game->map_info);
	game->mlx = mlx_init();
	init_minimap(game);
	init_texture(game);
	game->win = mlx_new_window(game->mlx, width + get_minimap_size(game), height, "cub3D");//map + minimap
	game->img.img = mlx_new_image(game->mlx, width, height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
