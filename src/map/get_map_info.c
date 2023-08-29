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

static int	*parse_rgb(char **rgb)
{
	int		*color_info;
	int		i;
	int		j;

	color_info = ft_calloc(3, sizeof(int));
	if (!color_info)
		exit_with_error("calloc error");
	i = 0;
	while (rgb[i])
	{
		j = 0;
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
		map = ft_calloc(i + 1, sizeof(char *));
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

bool	is_texture(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (true);
	return (false);
}

bool	is_color(char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
		return (true);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (true);
	return (false);
}
void	set_texture_path(t_map_info *map_info, char *line)
{
		if (ft_strncmp(line, "NO", 2) == 0)
		{
			if (map_info->north_texture)
				free(map_info->north_texture);
			map_info->north_texture = extract_texture_path(line);
		}
		else if (ft_strncmp(line, "SO", 2) == 0)
		{
			if (map_info->south_texture)
				free(map_info->south_texture);
			map_info->south_texture = extract_texture_path(line);
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			if (map_info->west_texture)
				free(map_info->west_texture);
			map_info->west_texture = extract_texture_path(line);
		}
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			if (map_info->east_texture)
				free(map_info->east_texture);
			map_info->east_texture = extract_texture_path(line);
		}
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

void	set_map(t_map_info *map_info, char *line, int fd)
{
		if (!are_completed_texture_and_color(map_info))
			exit_with_error("Please ensure that all required map details are provided");
		map_info->map = extract_map(fd, line, 1);
}

t_map_info	get_map_info(int fd)
{
	char		*line;
	t_map_info	map_info;

	init_map_info(&map_info);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_texture(line))
			set_texture_path(&map_info, line);
		else if (is_color(line))
			set_rbg(&map_info, line);
		else if (ft_strncmp(line, "\n", 1) != 0)
			set_map(&map_info, line, fd);
		free(line);
	}
	return (map_info);
}
