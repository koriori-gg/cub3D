#include "cub3d.h"

void	load_image(t_game *game, int *texture, char *path, t_image *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_line, &img->endian);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] = img->data[img->width * y + x];
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

void	init_buf(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			game->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_texture(t_game *game)
{
	int	i;
	int	j;

	game->re_buf = 0;
	init_buf(game);
	game->texture = (int **)ft_calloc(9, sizeof(int *));
	if (!game->texture)
		return ;
	i = 0;
	while (i < 9)
	{
		game->texture[i] = (int *)ft_calloc
			(TEXTURE_HEIGHT * TEXTURE_WIDTH, sizeof(int));
		if (!game->texture[i++])
			return ;
	}
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
			game->texture[i][j++] = 0;
		i++;
	}
	load_texture(game);
}
