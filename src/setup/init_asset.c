/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:52 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:53 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_image(t_game *game, int *texture, char *path, t_image *image)
{
	int	y;
	int	x;

	image->image = try_mlx_xpm_file_to_image(game->mlx, path,
			&image->width, &image->height);
	if (!image->image)
		exit_with_error("The provided path for the texture image is not valid");
	image->data = (int *)try_mlx_get_data_addr(image->image, &image->bpp,
			&image->size_line, &image->endian);
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			texture[image->width * y + x] = image->data[image->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, image->image);
}

static void	load_texture(t_game *game)
{
	t_image	image;

	load_image(game, game->texture[NORTH],
		game->map_info.north_texture, &image);
	load_image(game, game->texture[SOUTH],
		game->map_info.south_texture, &image);
	load_image(game, game->texture[WEST],
		game->map_info.west_texture, &image);
	load_image(game, game->texture[EAST],
		game->map_info.east_texture, &image);
}

static void	init_field_of_view_pixel_color(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			game->field_of_view_pixel_color[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_texture(t_game *game)
{
	int	i;
	int	j;

	init_field_of_view_pixel_color(game);
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
