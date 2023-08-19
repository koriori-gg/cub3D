#include "cub3d.h"

void	draw(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			game->img.data[y * width + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
