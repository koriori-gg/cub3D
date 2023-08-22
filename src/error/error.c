#include "cub3d.h"

void	print_error(char *str)
{
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
}

void	error_exit(int signal)
{
	print_error("Error\n");
	if (signal == AGUMENT_ERROR)
		print_error("Not enough arguments\n");
	if (signal == EMPTY_ERROR)
		print_error("Empty file\n");
	if (signal == EXTENTION_ERROR)
		print_error("Invalid file extension\n");
	if (signal == READ_ERROR)
		print_error("Failed to read\n");
	if (signal == MINIMUM_ERROR)
		print_error("Must contain N,S,E or W for the player's start position\n");
	if (signal == MALLOC_ERROR)
		print_error("fail to memory allocate\n");
	exit(1);
}
