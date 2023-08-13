#include "cub3d.h"

void	exit_with_error_message(char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}

bool	is_valid_filename(char *path)
{
	int	path_len;

	if (!path)
		return (false);
	path_len = ft_strlen(path);
	if (ft_strncmp(&path[path_len - 4], ".cub", 4))
		return (false);
	return (true);
}

bool	can_read_file(char *path)
{
	if (open(path, O_RDONLY) == -1)	
		return (false);
	return (true);
}


// ファイルがあるかどうか
// ファイルの読み取り権限があるかどうか
// ファイルの拡張子が.cubかどうか
t_cub_info *read_cub(char *path)
{
	t_cub_info *cub_info = NULL;

	if (!is_valid_filename(path))
		exit_with_error_message("invalid filename");
	if (!can_read_file(path))	
		exit_with_error_message("open file failed");
	return (cub_info);
}

int main(int argc, char *argv[])
{
	t_cub_info	*cub_info;

	if (argc != 2)
		exit_with_error_message("invalid input");
	cub_info = read_cub(argv[1]);
	return (0);
}