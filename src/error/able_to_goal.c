// #include "cub3d.h"

// static void	backtracking(t_map *map, int i)
// {
// 	if ((map->prev->row[i] == '1') && (map->row[i + 1] == '1')
// 		&& (map->row[i - 1] == '1') && (map->next->row[i] == '1'))
// 		return ;
// 	if (map->next->row[i] != '1')
// 	{
// 		map->next->row[i] = '1';
// 		backtracking(map->next, i);
// 	}
// 	if (map->prev->row[i] != '1')
// 	{
// 		map->prev->row[i] = '1';
// 		backtracking(map->prev, i);
// 	}
// 	if (map->row[i + 1] != '1')
// 	{
// 		map->row[i + 1] = '1';
// 		backtracking(map, i + 1);
// 	}
// 	if (map->row[i - 1] != '1')
// 	{
// 		map->row[i - 1] = '1';
// 		backtracking(map, i - 1);
// 	}
// }

// static void	dup_contain(t_base *data, t_map *dup, char *chars)
// {
// 	t_map	*map;
// 	size_t	i;
// 	char	*str;

// 	map = dup;
// 	while (map != NULL)
// 	{
// 		i = 0;
// 		str = map->row;
// 		while (str[i])
// 		{
// 			if (ft_strchr(chars, str[i]) == NULL)
// 			{
// 				ft_free_map(dup);
// 				error_free(data, UNABLETOGOAL_ERROR);
// 			}
// 			i++;
// 		}
// 		map = map->next;
// 	}
// }

// void	able_to_goal(t_base *data)
// {
// 	t_map	*dup;
// 	t_map	*head;
// 	int		i;

// 	dup = mapdup(data->map);
// 	head = dup;
// 	i = 0;
// 	while (dup != NULL)
// 	{
// 		if (i == data->index.y)
// 			break ;
// 		i++;
// 		dup = dup->next;
// 	}
// 	backtracking(dup, data->index.x);
// 	dup_contain(data, head, "01\n");
// 	ft_free_map(head);
// }
