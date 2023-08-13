#ifndef CUB3D_H
# define CUB3D_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

typedef struct s_cub_info {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	char	**map;
}	t_cub_info;

#endif