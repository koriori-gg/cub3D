/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:43 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:43 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	calculate_draw_end(int window_height, int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + window_height / 2;
	if (draw_end >= window_height)
		draw_end = window_height - 1;
	return (draw_end);
}

static int	calculate_draw_start(int window_height, int line_height)
{
	int	draw_start;

	draw_start = window_height / 2 - line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

void	prepare_map_draw(t_draw	*draw, double perpendicular_distance)
{
	draw->line_height = (int)(HEIGHT / perpendicular_distance);
	draw->draw_start = calculate_draw_start(HEIGHT, draw->line_height);
	draw->draw_end = calculate_draw_end(HEIGHT, draw->line_height);
}
