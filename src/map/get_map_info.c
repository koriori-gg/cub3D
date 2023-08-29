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
	if (!texture_info)
		exit_with_error("Memory allocation error");
	return (texture_info);
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
		if (rgb[i][j] == '\0' || rgb[i][j] == '\n')
			exit_with_error("RGB error");
		while (rgb[i][j] != '\0' && rgb[i][j] != '\n')
		{
			if (!ft_isdigit(rgb[i][j]))
				exit_with_error("not digit\n");
			j++;
		}
		color_info[i] = ft_atoi(rgb[i]);
		if (color_info[i] < 0 || color_info[i] > 255)
			exit_with_error("not in range\n");
		i++;
	}
	free_double_pointer(rgb);
	return (color_info);
}

static char	**extract_rgb(char *line)
{
	int		i;
	char	**rgb;

	i = 1;
	if (line[i] == '\0' || line[i] == '\n')
		exit_with_error("no info\n");
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
	return (rgb);
}

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
			exit_with_error("calloc error");
		return (map);
	}
	map = extract_map(fd, first_line, i + 1);
	if (ft_strchr(line, '\n'))
		map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		map[i] = ft_strdup(line);
	if (!map[i])
		exit_with_error("Memory allocation error");
	free(line);
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
			map_info.floor_color = parse_rgb(extract_rgb(line));
		else if (ft_strncmp(line, "C", 1) == 0)
			map_info.ceiling_color = parse_rgb(extract_rgb(line));
		else if (ft_strncmp(line, "\n", 1) != 0)
			map_info.map = extract_map(fd, line, 1);
		free(line);
	}
	return (map_info);
}
