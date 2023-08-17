#include "cub3d.h"

static bool	is_valid_filename(char *path)
{
	int	path_len;

	if (!path)
		return (false);
	path_len = ft_strlen(path);
	if (ft_strncmp(&path[path_len - 4], ".cub", 4))
		return (false);
	return (true);
}

static void	init_cub_info(t_cub_info *cub_info)
{
	cub_info->north_texture = NULL;
	cub_info->south_texture = NULL;
	cub_info->west_texture = NULL;
	cub_info->east_texture = NULL;
	cub_info->floor_color = NULL;
	cub_info->ceiling_color = NULL;
	cub_info->map = NULL;
}

bool	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

char	*cut_texture_info(char *line)
{
	int i;
	char *texture_info;
	
	i = 2;
	if (line[i] == '\0' || line[i] == '\n')	
		return (NULL);
	while (is_space(line[i]))
		i++;
	texture_info = ft_substr(&line[i], 0, ft_strlen(&line[i]) - 1);
	return (texture_info);
}
 
int	*cut_color_info(char *line)
{
	int i;
	char **rgb;
	int	*color_info;

	i = 1;
	if (line[i] == '\0' || line[i] == '\n')
		return (NULL); 
	while (is_space(line[i]))
		i++;
	rgb = ft_split(&line[i], ',');
	if (!rgb)
		return (NULL);
	i = 0;
	while (rgb[i])
		i++;
	color_info = ft_calloc(i + 1, sizeof(int));
	i = 0;
	while (rgb[i])
	{
		color_info[i] = ft_atoi(rgb[i]);
		i++;
	}
	return (color_info);
}

char	**cut_map_info(int fd, char *first_line, int i)
{
	char **map;
	char *line;

	line = get_next_line(fd);
	if (!line)
	{
		map = ft_calloc(i + 1, sizeof(char *));
		map[0] = ft_strdup(first_line);
		return (map);
	}
	map = cut_map_info(fd, first_line, i + 1);
	map[i] = line;
	return (map);
}

t_cub_info read_cub(char *path)
{
	int fd;
	char *line;
	t_cub_info cub_info;

	init_cub_info(&cub_info);
	if (!is_valid_filename(path))
		exit_with_error("invalid filename");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error("open file failed");

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "NO", 2) == 0)
			cub_info.north_texture = cut_texture_info(line);
		else if (ft_strncmp(line, "SO", 2) == 0)
			cub_info.south_texture = cut_texture_info(line);
		else if (ft_strncmp(line, "WE", 2) == 0)
			cub_info.west_texture = cut_texture_info(line);
		else if (ft_strncmp(line, "EA", 2) == 0)
			cub_info.east_texture = cut_texture_info(line);
		else if (ft_strncmp(line, "F", 1) == 0)
			cub_info.floor_color = cut_color_info(line);
		else if (ft_strncmp(line, "C", 1) == 0)
			cub_info.ceiling_color = cut_color_info(line);
		else if (ft_strncmp(line, "\n", 1) == 0)
			;
		else
			cub_info.map = cut_map_info(fd, line, 1);
		free(line);
	}
	return (cub_info);
}