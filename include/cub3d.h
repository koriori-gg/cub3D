#ifndef CUB3D_H
# define CUB3D_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

typedef struct s_map_info {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		*floor_color;
	int		*ceiling_color;
	char	**map;
	int		player_count;
}	t_map_info;

void		exit_with_error(char *message);
int			open_cub_file(char *path);
t_map_info	get_map_info(int fd);
void		free_double_pointer(void *ptr);
void		validate_map_info(t_map_info map_info);

// debug
void	print_info(t_map_info info);
void	print_two_dimensional_array(char **array);

#endif