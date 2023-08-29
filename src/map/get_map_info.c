#include "cub3d.h"

bool	is_texture_path(char *line)
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

bool	is_rgb(char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
		return (true);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (true);
	return (false);
}

t_map_info	get_map_info(int fd)
{
	char		*line;
	t_map_info	map_info;

	line = get_next_line(fd);
	if (!line)
		exit_with_error
			("Please make sure the file contains the necessary data");
	init_map_info(&map_info);
	while (1)
	{
		if (is_texture_path(line))
			set_texture_path(&map_info, line);
		else if (is_rgb(line))
			set_rbg(&map_info, line);
		else if (ft_strncmp(line, "\n", 1) != 0)
			set_map(&map_info, line, fd);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (map_info);
}
