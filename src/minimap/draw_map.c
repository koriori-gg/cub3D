#include "cub3d.h"

// void	draw_player_direction(t_game *game, int img_width, int img_height)//width heightにする
// {
// 	int	x;
// 	int	y;
// 	t_player *player;

// 	player = game->player;

// 	if (player->direction_x == 0)
// 		x = game->minimap.img_width / 2;
// 	else if (player->direction_x > 0)
// 		x = game->minimap.img_width;
// 	else
// 		x = 0;
// 	if (player->direction_y == 0)
// 		y = game->minimap.img_height / 2;
// 	else if (player->direction_y > 0)
// 		y = game->minimap.img_height;
// 	else
// 		y = 0;

// 	mlx_pixel_put(game->mlx, game->win, img_width + x, img_height + y, RGB_RED);
// }

// static void	draw_image(t_game *game, char *str, int i, int j)
// {
// 	int	img_width;
// 	int	img_height;

// 	img_width = width + i * game->minimap.img_width;
// 	img_height = j * game->minimap.img_height;
// 	if (str[i] == '0')
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[0], img_width, img_height);
// 	else if (ft_strchr("1", str[i]))
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[1], img_width, img_height);
// 	else if (ft_strchr("2", str[i]))
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[2], img_width, img_height);
// 	else if (ft_strchr("3", str[i]))
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[3], img_width, img_height);
// 	else if (ft_strchr("4", str[i]))
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[4], img_width, img_height);
// 	else if (ft_strchr("56789", str[i]))
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[5], img_width, img_height);
// 	else if (ft_strchr("NSWE", str[i]))
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			game->minimap.tile_img[6], img_width, img_height);
// 		draw_player_direction(game, img_width, img_height);
// 	}
// }

// void	draw_map(t_game *game)
// {
// 	t_map	*head;
// 	char	*str;
// 	int		i;
// 	int		j;

// 	head = game->map_info->map;
// 	j = 0;
// 	while (head)
// 	{
// 		i = 0;
// 		str = head->row;
// 		while (str[i])
// 		{
// 			draw_image(game, str, i, j);
// 			i++;
// 		}
// 		j++;
// 		head = head->next;
// 	}
// }
