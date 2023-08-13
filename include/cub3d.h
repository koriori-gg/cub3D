#ifndef CUB3D_H
# define CUB3D_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

typedef struct s_cub_info {
	char				*line;
	struct s_cub_info	*next;	
}	t_cub_info;

#endif