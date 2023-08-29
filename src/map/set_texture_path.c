/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:22 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 21:30:27 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_texture_path(char *line)
{
	int		i;
	char	*texture_info;

	i = 2;
	if (line[i] == '\0' || line[i] == '\n')
		exit_with_error("no info\n");
	while (ft_isspace(line[i]))
		i++;
	texture_info = ft_substr(&line[i], 0, ft_strlen(&line[i]) - 1);
	return (texture_info);
}

void	set_texture_path(t_map_info *map_info, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (map_info->north_texture)
			exit_with_error("Please make sure to avoid duplicate texture");
		map_info->north_texture = extract_texture_path(line);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (map_info->south_texture)
			exit_with_error("Please make sure to avoid duplicate texture");
		map_info->south_texture = extract_texture_path(line);
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (map_info->west_texture)
			exit_with_error("Please make sure to avoid duplicate texture");
		map_info->west_texture = extract_texture_path(line);
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (map_info->east_texture)
			exit_with_error("Please make sure to avoid duplicate texture");
		map_info->east_texture = extract_texture_path(line);
	}
}
