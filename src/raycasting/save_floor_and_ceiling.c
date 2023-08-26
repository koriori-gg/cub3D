#include "cub3d.h"

void	save_ceiling(t_game *game, t_draw *draw, int x)
{
	int	y;
	int	color;

	y = 0;
	while (y < draw->draw_start)
	{
		color = 928742;
		game->buf[y][x] = color;
		y++;
	}
}

void	save_floor(t_game *game, t_draw *draw, int x)
{
	int	y;
	int	color;

	y = draw->draw_end;
	while (y < HEIGHT)
	{
		color = 646490;
		game->buf[y][x] = color;
		y++;
	}
}
