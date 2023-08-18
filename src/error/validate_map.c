#include "cub3d.h"

// static size_t	count_character(char *str, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// static void	exists_a_player(t_map *map)
// {
// 	t_map	*head;
// 	size_t	player;

// 	head = map;
// 	player = 0;
// 	while (map)
// 	{
// 		player += count_character(map->row, 'N');
// 		player += count_character(map->row, 'S');
// 		player += count_character(map->row, 'E');
// 		player += count_character(map->row, 'W');
// 		map = map->next;
// 	}
// 	if (player != 1)
// 	{
// 		ft_free_map(head);
// 		error_exit(MINIMUM_ERROR);
// 	}
// }

// static void	contains_unnecessary(t_map *map, char *chars)
// {
// 	t_map	*head;
// 	size_t	i;
// 	char	*str;

// 	head = map;
// 	while (map)
// 	{
// 		i = 0;
// 		str = map->row;
// 		while (str && str[i])
// 		{
// 			if (!ft_strchr(chars, str[i]))
// 			{
// 				ft_free_map(head);
// 				error_exit(UNNESSESARY_ERROR);
// 			}
// 			i++;
// 		}
// 		map = map->next;
// 	}
// }

// static void	check_surrounded(t_map *map)
// {
// 	t_map	*map;
// 	int		i;
// 	int		j;

// 	map = data->map;
// 	i = 1;
// 	while (map != NULL)
// 	{
// 		j = 0;
// 		while (map->row[j] != '\n')
// 		{
// 			if ((i == 1 || i == data->map_height) && (map->row[j] != '1'))
// 				error_free(data, SURROUND_ERROR);
// 			else if ((i != 1 && i != data->map_height)
// 				&& (j == 0 || j + 1 == data->map_width) && map->row[j] != '1')
// 				error_free(data, SURROUND_ERROR);
// 			j++;
// 		}
// 		i++;
// 		map = map->next;
// 	}
// }

// void	validate_map(char **argv)
// {
// 	// t_mapinfo	*map_info;

// 	// map_info = init_mapinfo(argv);
// 	// print_map_info(map_info);
// 	// exists_a_player(map_info->map);
// 	// contains_unnecessary(map_info->map, " 01NSEW\n");
// 	// // check_surrounded(map_info->map);
// 	// // able_to_goal(map_info->map,);
// 	// free_map_info(map_info);
// }