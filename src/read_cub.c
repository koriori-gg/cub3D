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
	cub_info->floor_color[0] = -1;
	cub_info->ceiling_color[0] = -1;
	cub_info->map = NULL;
}

bool	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

void	cut_texture_info(char **texture_info, char *line)
{
	int i;
	int len;
	
	i = 2;
	if (line[i] == '\0' || line[i] == '\n')	
		return ;
	while (is_space(line[i]))
		i++;
	len = ft_strlen(&line[i]);
	*texture_info = ft_calloc(len, sizeof(char));
	ft_strlcpy(*texture_info, &line[i], len);
}

void	cut_color_info(int *color_info, char *line)
{
	int i;
	char **rgb;

	i = 1;
	if (line[i] == '\0')
		return ; 
	while (is_space(line[i]))
		i++;
	rgb = ft_split(&line[i], ',');
	if (!rgb)
		return ;
	color_info[0] = ft_atoi(rgb[0]);
	color_info[1] = ft_atoi(rgb[1]);
	color_info[2] = ft_atoi(rgb[2]);
	free_double_pointer(rgb);
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
			cut_texture_info(&cub_info.north_texture, line);
		else if (ft_strncmp(line, "SO", 2) == 0)
			cut_texture_info(&cub_info.south_texture, line);
		else if (ft_strncmp(line, "WE", 2) == 0)
			cut_texture_info(&cub_info.west_texture, line);
		else if (ft_strncmp(line, "EA", 2) == 0)
			cut_texture_info(&cub_info.east_texture, line);
		else if (ft_strncmp(line, "F", 1) == 0)
			cut_color_info(cub_info.floor_color, line);
		else if (ft_strncmp(line, "C", 1) == 0)
			cut_color_info(cub_info.ceiling_color, line);
		
		free(line);
	}	
	return (cub_info);
}