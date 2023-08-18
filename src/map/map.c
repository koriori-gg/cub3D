#include "cub3d.h"

t_map	*ft_mapnew(char *str, size_t y)
{
	t_map	*ret;

	ret = ft_calloc(1, sizeof(t_map));
	if (!ret)
		return (NULL);
	ret->row = str;
	ret->y = y;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

int	ft_mapsize(t_map *map)
{
	int	size;

	size = 0;
	if (!map)
		return (0);
	while (map->next != NULL)
	{
		size++;
		map = map->next;
	}
	return (size + 1);
}

void	ft_mapadd_back(t_map **map, t_map *new)
{
	t_map	*ptr;
	int		size;

	if (!*map)
		*map = new;
	else
	{
		ptr = *map;
		size = ft_mapsize(*map);
		while (size > 1)
		{
			ptr = ptr->next;
			size--;
		}
		ptr->next = new;
		new->prev = ptr;
	}
}

void	ft_free_map(t_map *map)
{
	t_map	*ptr;

	while (map != NULL)
	{
		ptr = map;
		map = map->next;
		free(ptr->row);
		free(ptr);
	}
}

t_map	*mapdup(t_map *map)
{
	t_map	*ret;
	size_t	y;

	y = 0;
	while (map != NULL)
	{
		if (y == 0)
			ret = ft_mapnew(ft_strdup(map->row), y);
		else
			ft_mapadd_back(&ret, ft_mapnew(ft_strdup(map->row), y));
		y++;
		map = map->next;
	}
	return (ret);
}
