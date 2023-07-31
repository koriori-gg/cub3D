#include "cub3d.h"

void	draw_player_direction(t_game *game, int img_width, int img_height)//width heightにする
{
	int	x;
	int	y;
	t_player *player;

	player = game->player;

	if (player->direction_x == 0)
		x = game->img_width / 2;
	else if (player->direction_x > 0)
		x = game->img_width;
	else if (player->direction_x < 0)
		x = 0;
	if (player->direction_y == 0)
		x = game->img_height / 2;
	else if (player->direction_y > 0)
		x = game->img_height;
	else if (player->direction_y < 0)
		x = 0;

	mlx_pixel_put(game->mlx, game->win, img_width + x, img_height + y, RGB_RED);
}

static void	draw_image(t_game *game, char *str, int i, int j)
{
	int	img_width;
	int	img_height;

	img_width = width + i * game->img_width;
	img_height = j * game->img_height;
	if (str[i] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img[0], img_width, img_height);
	else if (ft_strchr("123456789", str[i]))
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img[1], img_width, img_height);
	else if (ft_strchr("NSWE", str[i]))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img[2], img_width, img_height);
		draw_player_direction(game, img_width, img_height);
	}
}

void	draw_map(t_game *game)
{
	t_map	*map_head;
	char	*str;
	int		i;
	int		j;

	map_head = game->map_info->map;
	j = 0;
	while (map_head)
	{
		i = 0;
		str = map_head->row;
		while (str[i])
		{
			draw_image(game, str, i, j);
			i++;
		}
		j++;
		map_head = map_head->next;
	}
}
