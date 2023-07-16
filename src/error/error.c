#include "cub3d.h"

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
	exit(1);
}
