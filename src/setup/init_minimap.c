/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:54 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*try_xpm_to_image(t_game *game, char *str)
{
	char	*path;
	void	*image;

	path = ft_strjoin("textures/minimap/", str);
	if (!path)
		exit_with_error("Memory allocation error");
	image = try_mlx_xpm_file_to_image(game->mlx, path, &game->minimap.width,
			&game->minimap.height);
	free(path);
	if (!image)
		exit_with_error("The path for the .xpm image is incorrect");
	return (image);
}

void	init_minimap(t_game *game)
{
	game->minimap.width = 5;
	game->minimap.height = 5;
	game->minimap.grid_image[FLOOR] = try_xpm_to_image(game, "floor.xpm");
	game->minimap.grid_image[WALL] = try_xpm_to_image(game, "wall.xpm");
	game->minimap.grid_image[PLAYER] = try_xpm_to_image(game, "player.xpm");
}
