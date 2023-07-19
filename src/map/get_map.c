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

// void	set_rgb(t_rgb **color, char *str)
// {
// 	char **rgb;

// 	rgb = ft_split(&str[2],',');//スペースの数に上限がないならspaceでsplitしてsplit
// 	//TODO: check split len
// 	print_argv(rgb);
// 	printf("rgb %s %s %s\n", rgb[0], rgb[1], rgb[2]);
// 	printf("%d\n", ft_atoi(rgb[0]));
// 	(*color)->red = ft_atoi(rgb[0]);
// 	printf("rgb %s %s %s\n", rgb[0], rgb[1], rgb[2]);
// 	if (!(*color)->red)
// 		error_exit(MALLOC_ERROR);//add free
// 	(*color)->green =ft_atoi(rgb[1]);
// 	if (!(*color)->green)
// 		error_exit(MALLOC_ERROR);//add free
// 	(*color)->blue = ft_atoi(rgb[2]);
// 	if (!(*color)->blue)
// 		error_exit(MALLOC_ERROR);//add free
// 	free_double_pointer(rgb);
// }

static char	*join_line_feed(char *str)
{
	char	*new;

	new = ft_strjoin(str, "\n");
	free(str);
	return (new);
}

void	add_mapinfo(t_mapinfo **map_info, char *str)
{
	printf("add %s\n", str);
	if (ft_strncmp(str,"NO", 2) == 0)
		(*map_info)->north_texture = str;
	if (ft_strncmp(str,"SO", 2) == 0)
		(*map_info)->south_texture = str;
	if (ft_strncmp(str,"WE", 2) == 0)
		(*map_info)->west_texture = str;
	if (ft_strncmp(str,"EA", 2) == 0)
		(*map_info)->east_texture = str;
	if (ft_strncmp(str,"F", 1) == 0)
		// set_rgb(&(*map_info)->floor_color, str);
		return ;
	if (ft_strncmp(str,"C", 1) == 0)
		// set_rgb(&(*map_info)->ceiling_color, str);
		return ;
}

void	add_map(t_mapinfo **map_info, char *str, size_t i)
{
	t_map *map;

	map = (*map_info)->map;
	if (!ft_strchr(str, '\n'))
		str = join_line_feed(str);
	printf("map %s\n", str);
	if (i == 1)
		map = ft_mapnew(str);
	else
		ft_mapadd_back(&map, ft_mapnew(str));
}

//TODO: check leak
void	get_map_info(t_mapinfo **map_info, char **argv)
{
	int		fd;
	char	*str;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		error_exit(EMPTY_ERROR);
	while (str)
	{
		if (is_elements_info(str))
			add_mapinfo(map_info, str);
		// else
		// {
		// 	printf("Hoge\n");
		// 	add_map(map_info, str, i);//strをポインタで渡した方がいい?
		// 	i++;
		// }
		str = get_next_line(fd);
	}
	close(fd);
}
