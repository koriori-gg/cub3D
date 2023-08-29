#include "cub3d.h"

static void	load_image(t_game *game, int *texture, char *path, t_image *img)
{
	int	y;
	int	x;

	img->img = try_mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (!img->img)
		exit_with_error("Invalid asset file path");
	img->data = (int *)try_mlx_get_data_addr(img->img, &img->bpp,
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

static void	load_texture(t_game *game)
{
	t_image	img;

	load_image(game, game->texture[NORTH], game->map_info.north_texture, &img);
	load_image(game, game->texture[SOUTH], game->map_info.south_texture, &img);
	load_image(game, game->texture[WEST], game->map_info.west_texture, &img);
	load_image(game, game->texture[EAST], game->map_info.east_texture, &img);
}

static void	init_buf(t_game *game)
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

	init_buf(game);
	game->texture = (int **)ft_calloc(4, sizeof(int *));
	if (!game->texture)
		return ;
	i = 0;
	while (i < 4)
	{
		game->texture[i] = (int *)ft_calloc
			(TEXTURE_HEIGHT * TEXTURE_WIDTH, sizeof(int));
		if (!game->texture[i++])
			return ;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
			game->texture[i][j++] = 0;
		i++;
	}
	load_texture(game);
}
