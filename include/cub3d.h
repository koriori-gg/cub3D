#ifndef CUB3D_H
# define CUB3D_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx_int.h"
# include "mlx.h"

# define KEY_PRESS		2
# define RED_CLOSS		17

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_UP			65362
# define KEY_LEFT		65361
# define KEY_DOWN		65364
# define KEY_RIGHT		65363

typedef struct s_game {
	void		*mlx;
	void		*win;
}				t_game;

#endif