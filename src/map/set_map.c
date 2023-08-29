/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:16 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 21:07:22 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**extract_map(int fd, char *first_line, int i)
{
	char	**map;
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		map = try_calloc(i + 1, sizeof(char *));
		if (ft_strchr(first_line, '\0'))
			map[0] = ft_substr(first_line, 0, ft_strlen(first_line) - 1);
		else
			map[0] = ft_strdup(first_line);
		if (!map[0])
			exit_with_error("Memory allocation error");
		return (map);
	}
	map = extract_map(fd, first_line, i + 1);
	if (ft_strchr(line, '\n'))
		map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		map[i] = ft_strdup(line);
	free(line);
	return (map);
}

bool	are_completed_texture_and_color(t_map_info *map_info)
{
	if (!map_info->north_texture)
		return (false);
	if (!map_info->south_texture)
		return (false);
	if (!map_info->west_texture)
		return (false);
	if (!map_info->east_texture)
		return (false);
	if (!map_info->floor_color)
		return (false);
	if (!map_info->ceiling_color)
		return (false);
	return (true);
}

void	set_map(t_map_info *map_info, char *line, int fd)
{
	if (!are_completed_texture_and_color(map_info))
		exit_with_error
			("Please ensure that all required map details are provided");
	map_info->map = extract_map(fd, line, 1);
}
