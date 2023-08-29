#include "cub3d.h"

void	*try_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(n, size);
	if (!ptr)
		exit_with_error("Memory allocation error");
	return (ptr);
}
