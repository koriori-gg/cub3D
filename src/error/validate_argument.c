#include "cub3d.h"

static void	validate_file(char *arg)
{
	char	*ptr;
	int		fd;

	ptr = ft_strrchr(arg, '.');
	if (ptr == NULL)
		error_exit(EXTENTION_ERROR);
	if (ft_memcmp(ptr, ".cub", 4) != 0)
		error_exit(EXTENTION_ERROR);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_exit(READ_ERROR);
	close(fd);
}

void	validate_argument(int argc, char **argv)
{
	if (argc < 2)
		error_exit(AGUMENT_ERROR);
	validate_file(argv[1]);//TODO: change 複数map対応
	validate_map(argv);
}