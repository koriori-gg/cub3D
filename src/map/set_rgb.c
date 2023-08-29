/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokuno <sokuno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:19 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 21:14:12 by sokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**extract_rgb(char *line)
{
	int		i;
	char	**rgb;

	i = 1;
	if (line[i] == '\0' || line[i] == '\n')
		exit_with_error("The texture paths (NO, SO, WE, EA) must be provided");
	while (ft_isspace(line[i]))
		i++;
	rgb = ft_split(&line[i], ',');
	if (!rgb)
		exit_with_error("Memory allocation error");
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		exit_with_error("RGB values should be entered in the format R,G,B");
	return (rgb);
}

static int	*parse_rgb(char **rgb)
{
	int		*color_info;
	int		i;
	int		j;

	color_info = try_calloc(3, sizeof(int));
	i = 0;
	while (rgb[i])
	{
		j = 0;
		if (rgb[i][j] != '\0' || rgb[i][j] != '\0')
			exit_with_error("RGB values must be entered in format R,G,B");
		while (rgb[i][j] != '\0' && rgb[i][j] != '\n')
		{
			if (!ft_isdigit(rgb[i][j]))
				exit_with_error("RGB values must be numeric");
			j++;
		}
		color_info[i] = ft_atoi(rgb[i]);
		if (color_info[i] < 0 || color_info[i] > 255)
			exit_with_error("RGB values must be between 0 and 255");
		i++;
	}
	free_double_pointer(rgb);
	return (color_info);
}

void	set_rbg(t_map_info *map_info, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (map_info->floor_color)
			free(map_info->floor_color);
		map_info->floor_color = parse_rgb(extract_rgb(line));
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (map_info->ceiling_color)
			free(map_info->ceiling_color);
		map_info->ceiling_color = parse_rgb(extract_rgb(line));
	}
}
