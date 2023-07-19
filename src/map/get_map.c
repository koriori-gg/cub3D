#include "cub3d.h"

static bool	is_elements_info(char *str)//TODO:mapにNOとかが入ってるパターンを考慮
{
	if (ft_strncmp(str,"NO", 2) == 0)
		return (true);
	if (ft_strncmp(str,"SO", 2) == 0)
		return (true);
	if (ft_strncmp(str,"WE", 2) == 0)
		return (true);
	if (ft_strncmp(str,"EA", 2) == 0)
		return (true);
	if (ft_strncmp(str,"F", 1) == 0)
		return (true);
	if (ft_strncmp(str,"C", 1) == 0)
		return (true);
	return (false);
}

t_rgb	*set_rgb(char *str)
{
	t_rgb *color;
	char **rgb;

	color = (t_rgb *)ft_calloc(sizeof(t_rgb), 1);
	rgb = ft_split(&str[2],',');//スペースの数に上限がないからspaceでsplitしてsplit
	//TODO: check split len
	color->red = ft_atoi(rgb[0]);
	color->green =ft_atoi(rgb[1]);
	color->blue = ft_atoi(rgb[2]);
	free_double_pointer(rgb);
	return (color);
}

static char	*join_line_feed(char *str)
{
	char	*new;

	new = ft_strjoin(str, "\n");
	free(str);
	return (new);
}

void	add_mapinfo(t_mapinfo *map_info, char *str)
{
	if (ft_strncmp(str,"NO", 2) == 0)
		map_info->north_texture = str;
	if (ft_strncmp(str,"SO", 2) == 0)
		map_info->south_texture = str;
	if (ft_strncmp(str,"WE", 2) == 0)
		map_info->west_texture = str;
	if (ft_strncmp(str,"EA", 2) == 0)
		map_info->east_texture = str;
	if (ft_strncmp(str,"F", 1) == 0)
		map_info->floor_color = set_rgb(str);
	if (ft_strncmp(str,"C", 1) == 0)
		map_info->ceiling_color = set_rgb(str);
}

void	add_map(t_mapinfo *map_info, char *str, size_t i)
{
	t_map *map;

	map = map_info->map;
	if (!ft_strchr(str, '\n'))
		str = join_line_feed(str);
	ft_mapadd_back(&map, ft_mapnew(str));
}

//TODO: check leak
t_mapinfo	*get_map_info(char **argv)
{
	t_mapinfo	*map_info;
	int			fd;
	char		*str;
	size_t		i;

	map_info = (t_mapinfo *)ft_calloc(sizeof(t_mapinfo), 1);
	map_info->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	i = 1;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		error_exit(EMPTY_ERROR);
	while (str)
	{
		if (is_elements_info(str))
			add_mapinfo(map_info, str);
		else
		{
			add_map(map_info, str, i);//strをポインタで渡した方がいい?
			i++;
		}
		str = get_next_line(fd);
	}
	close(fd);
	return (map_info);
}
