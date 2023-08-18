// #include "cub3d.h"

// bool	is_elements_info(char *str)//TODO:mapにNOとかが入ってるパターンを考慮
// {
// 	if (ft_strncmp(str,"NO", 2) == 0)
// 		return (true);
// 	if (ft_strncmp(str,"SO", 2) == 0)
// 		return (true);
// 	if (ft_strncmp(str,"WE", 2) == 0)
// 		return (true);
// 	if (ft_strncmp(str,"EA", 2) == 0)
// 		return (true);
// 	if (ft_strncmp(str,"F", 1) == 0)
// 		return (true);
// 	if (ft_strncmp(str,"C", 1) == 0)
// 		return (true);
// 	return (false);
// }

// void	free_map_info(t_mapinfo *map_info)
// {
// 	//add:
// 	free(map_info->north_texture);
// 	free(map_info->south_texture);
// 	free(map_info->west_texture);
// 	free(map_info->east_texture);
// 	free(map_info->floor_color);
// 	free(map_info->ceiling_color);
// 	ft_free_map(map_info->map);
// 	free(map_info);
// }
