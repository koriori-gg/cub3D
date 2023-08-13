#include "cub3d.h"

void	free_double_pointer(void *ptr)
{
	void	**tmp;
	int		i;

	tmp = (void **)ptr;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
