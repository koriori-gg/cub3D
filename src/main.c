#include "project.h"

#include "project.h"

int main(int argc, char **argv)
{
	int fd = 0;

	if (argc > 1)
	{
		char *str;
		fd = open(argv[1], O_RDONLY);
		int i = 0;
		while (1)
		{
			str = get_next_line(fd);
			ft_printf("%s", str);
			if (!str)
			{
				free(str);
				break ;
			}
			free(str);
			i++;
		}
		close(fd);
	}
	else
	{
		while (1)
		{
			char *read_ret = get_next_line(fd);
			fprintf(stderr, "read ret : %s\n", read_ret);
			if (read_ret <= 0)
				break;
		}		
	}
}