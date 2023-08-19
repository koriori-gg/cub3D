#include "cub3d.h"

void	draw_player_direction(t_game *game, int img_width, int img_height)//TODO:width heightにする
{
	int			x;
	int			y;
	t_player	*player;

	player = game->player;
	if (player->direction_x == 0)
		x = game->minimap.img_width / 2;
	else if (player->direction_x > 0)
		x = game->minimap.img_width - 1;
	else
		x = 0;
	if (player->direction_y == 0)
		y = game->minimap.img_height / 2;
	else if (player->direction_y > 0)
		y = game->minimap.img_height - 1;
	else
		y = 0;
	mlx_pixel_put(game->mlx, game->win, img_width + x, img_height + y, RGB_RED);
}

static void	draw_player(t_game *game, int x, int y)
{
	int	img_width;
	int	img_height;

	img_width = width + x * game->minimap.img_width;
	img_height = y * game->minimap.img_height;
	mlx_put_image_to_window(game->mlx, game->win,
		game->minimap.tile_img[6], img_width, img_height);
	draw_player_direction(game, img_width, img_height);
}

static void	draw_image(t_game *game, char c, int x, int y)
{
	int	img_width;
	int	img_height;

	img_width = width + x * game->minimap.img_width;
	img_height = y * game->minimap.img_height;
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.tile_img[0], img_width, img_height);
	else if (ft_strchr("1", c))
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.tile_img[1], img_width, img_height);
	else if (ft_strchr("2", c))
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.tile_img[2], img_width, img_height);
	else if (ft_strchr("3", c))
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.tile_img[3], img_width, img_height);
	else if (ft_strchr("4", c))
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.tile_img[4], img_width, img_height);
	else if (ft_strchr("56789", c))
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.tile_img[5], img_width, img_height);
}

void	draw_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map_info.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (y == (int)game->player->position_y
				&& x == (int)game->player->position_x)
				draw_player(game, x, y);
			else
				draw_image(game, map[y][x], x, y);
			x++;
		}
		y++;
	}
}
