#include "cub3d.h"

void	exit_with_error_message(char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
		exit_with_error_message("invalid input");
}