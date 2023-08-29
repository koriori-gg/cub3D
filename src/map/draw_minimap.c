/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:10 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:10 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player_direction(t_game *game, int width, int height)
{
	int			x;
	int			y;
	t_player	*player;

	player = game->player;
	if (player->direction_x >= -0.5 && player->direction_x <= 0.5)
		x = game->minimap.width / 2;
	else if (player->direction_x > 0.5)
		x = game->minimap.width - 1;
	else
		x = 0;
	if (player->direction_y >= -0.5 && player->direction_y <= 0.5)
		y = game->minimap.height / 2;
	else if (player->direction_y > 0.5)
		y = game->minimap.height - 1;
	else
		y = 0;
	mlx_pixel_put(game->mlx, game->win, width + x, height + y, RGB_RED);
}

static void	draw_player(t_game *game, int x, int y)
{
	int	width;
	int	height;

	width = WIDTH + x * game->minimap.width;
	height = y * game->minimap.height;
	mlx_put_image_to_window(game->mlx, game->win,
		game->minimap.grid_image[PLAYER], width, height);
	draw_player_direction(game, width, height);
}

static void	draw_image(t_game *game, char c, int x, int y)
{
	int	width;
	int	height;

	width = WIDTH + x * game->minimap.width;
	height = y * game->minimap.height;
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.grid_image[FLOOR], width, height);
	else if (ft_strchr("1", c))
		mlx_put_image_to_window(game->mlx, game->win,
			game->minimap.grid_image[WALL], width, height);
}

void	draw_minimap(t_game *game)
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
