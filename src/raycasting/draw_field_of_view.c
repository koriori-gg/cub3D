#include "cub3d.h"

void	draw_field_of_view(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			game->image.data[y * WIDTH + x]
				= game->field_of_view_pixel_color[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.image, 0, 0);
}
