/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:24 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:29:24 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_map(char **map)
{
	ensure_valid_object_structure(map);
	ensure_map_enclosed_by_wall(map);
}
