#include "cub3d.h"

void	save_ceiling(t_game *game, t_draw *draw, int x)
{
	int		y;
	int		color;
	int		*ceiling_color;

	ceiling_color = game->map_info.ceiling_color;
	y = 0;
	color = ceiling_color[0] << 16 | ceiling_color[1] << 8 | ceiling_color[2];
	while (y < draw->draw_start)
	{
		game->buf[y][x] = color;
		y++;
	}
}

void	save_floor(t_game *game, t_draw *draw, int x)
{
	int		y;
	int		color;
	int		*floor_color;

	floor_color = game->map_info.floor_color;
	y = draw->draw_end;
	color = floor_color[0] << 16 | floor_color[1] << 8 | floor_color[2];
	while (y < HEIGHT)
	{
		game->buf[y][x] = color;
		y++;
	}
}
