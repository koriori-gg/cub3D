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

int	open_cub_file(char *path)
{
	int	fd;

	if (!is_valid_filename(path))
		exit_with_error("Please use a file with the .cub extension");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error("Please ensure the file exists and the path is valid");
	return (fd);
}
