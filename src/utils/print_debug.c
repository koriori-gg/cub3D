#include "cub3d.h"

void	print_argv(char **argv)
{
	int	i;

	printf("==argv==\n");
	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("--map--\n");
	while (map)
	{
		if (i < 10)
			printf("[  %d] %s",i, map->row);
		else if (i < 100)
			printf("[ %d] %s",i, map->row);
		else if (i < 1000)
			printf("[%d] %s",i, map->row);
		map = map->next;
		i++;
	}
}
