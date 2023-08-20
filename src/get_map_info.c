#include "cub3d.h"

static char	*extract_texture_path(char *line)
{
	int		i;
	char	*texture_info;

	i = 2;
	if (line[i] == '\0' || line[i] == '\n')
		return (NULL);
	while (ft_isspace(line[i]))
		i++;
	texture_info = ft_substr(&line[i], 0, ft_strlen(&line[i]) - 1);
	return (texture_info);
}

static int	*extract_rgb(char *line)
{
	int		i;
	int		j;
	char	**rgb;
	int		*color_info;

	i = 1;
	if (line[i] == '\0' || line[i] == '\n')
		return (NULL);
	while (ft_isspace(line[i]))
		i++;
	rgb = ft_split(&line[i], ',');
	if (!rgb)
		exit_with_error("ft_split failed\n");
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		exit_with_error("num of dot error\n");
	color_info = ft_calloc(i + 1, sizeof(int));
	if (!color_info)
		exit_with_error("calloc falied\n");
	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] != '\0' && rgb[i][j] != '\n')
		{
			printf("%c\n", rgb[i][j]);
			if (!ft_isdigit(rgb[i][j]))
				exit_with_error("not digit\n");
			j++;
		}
		color_info[i] = ft_atoi(rgb[i]);
		i++;
	}
	free_double_pointer(rgb);
	return (color_info);
}

static char	**extract_map(int fd, char *first_line, int i)
{
	char	**map;
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		map = ft_calloc(i + 1, sizeof(char *));
		map[0] = ft_strdup(first_line);
		return (map);
	}
	map = extract_map(fd, first_line, i + 1);
	map[i] = line;
	return (map);
}

t_map_info	get_map_info(int fd)
{
	char		*line;
	t_map_info	map_info;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "NO", 2) == 0)
			map_info.north_texture = extract_texture_path(line);
		else if (ft_strncmp(line, "SO", 2) == 0)
			map_info.south_texture = extract_texture_path(line);
		else if (ft_strncmp(line, "WE", 2) == 0)
			map_info.west_texture = extract_texture_path(line);
		else if (ft_strncmp(line, "EA", 2) == 0)
			map_info.east_texture = extract_texture_path(line);
		else if (ft_strncmp(line, "F", 1) == 0)
			map_info.floor_color = extract_rgb(line);
		else if (ft_strncmp(line, "C", 1) == 0)
			map_info.ceiling_color = extract_rgb(line);
		else if (ft_strncmp(line, "\n", 1) != 0)
			map_info.map = extract_map(fd, line, 1);
		free(line);
	}
	return (map_info);
}
