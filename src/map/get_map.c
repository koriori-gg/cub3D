#include "cub3d.h"

static char	*join_line_feed(char *str)
{
	char	*new;

	new = ft_strjoin(str, "\n");
	free(str);
	return (new);
}
//TODO: leak
void	get_map(t_map **map, char **argv)//mapがpointerではあかん?
{
	int		fd;
	char	*str;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			if (i == 1)
				error_exit(EMPTY_ERROR);
			free(str);
			break ;
		}
		if (!ft_strchr(str, '\n'))
			str = join_line_feed(str);
		if (i == 1)
			*map = ft_mapnew(str);//TODO: もしかしたらadd backだけで良い?
		else
			ft_mapadd_back(map, ft_mapnew(str));
		i++;
	}
	close(fd);
}
