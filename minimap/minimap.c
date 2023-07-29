#include "cub3d.h"

static void	draw_image(t_game *game, char *str, int i, int j)
{
	int	img_width;
	int	img_height;

	img_width = i * game->img_width;
	img_height = j * game->img_height;
	if (str[i] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img[0], img_width, img_height);
	else if (str[i] >= '1' && str[i] <= '9')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_img[1], img_width, img_height);
}

void	draw_map(t_game *game)
{
	t_map	*map_top;
	char	*str;
	int		i;
	int		j;

	map_top = game->map;
	j = 0;
	while (map_top != NULL)
	{
		i = 0;
		str = map_top->row;
		while (str[i])
		{
			draw_image(game, str, i, j);
			i++;
		}
		j++;
		map_top = map_top->next;
	}
}
