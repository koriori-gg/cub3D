/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_field_of_view.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:37 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:37 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_field_of_view(t_game *game)
{
	int		x;
	t_dda	dda;
	t_draw	draw;

	x = 0;
	while (x < WIDTH)
	{
		prepare_calculate_collision_grid(game, &dda, x);
		dda.is_y_collision = calculate_collision_grid(game, &dda);
		if (!dda.is_y_collision)
			dda.perpendicular_distance
				= (dda.collision_grid_x - game->player->position_x
					+ (1 - dda.step_x) / 2) / dda.ray_direction_x;
		else
			dda.perpendicular_distance
				= (dda.collision_grid_y - game->player->position_y
					+ (1 - dda.step_y) / 2) / dda.ray_direction_y;
		prepare_map_draw(&draw, dda.perpendicular_distance);
		save_color(game, &dda, &draw, x);
		x++;
	}
}
