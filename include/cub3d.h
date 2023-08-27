#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <math.h>

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
# define X_EVENT_KEY_PRESS	2

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define WIDTH 960
# define HEIGHT 540

# define RGB_RED 0xFF0000

# define DIR_DOWN		0
# define DIR_UP			1
# define DIR_RIGHT		2
# define DIR_LEFT		3

enum e_message
{
	AGUMENT_ERROR,
	EMPTY_ERROR,
	EXTENTION_ERROR,
	READ_ERROR,
	MINIMUM_ERROR,
	UNNESSESARY_ERROR,
	SURROUND_ERROR,
	RECTANGLE_ERROR,
	UNABLETOGOAL_ERROR,
	IMAGE_ERROR,
	MLX_ERROR,
	MALLOC_ERROR
};

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef struct s_map_info {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		*floor_color;
	int		*ceiling_color;
	char	**map;
}	t_map_info;

typedef struct s_player {
	double	pre_position_x;
	double	pre_position_y;
	double	position_x;
	double	position_y;
	double	direction_x;
	double	direction_y;
	double	angle_x;
	double	angle_y;
	double	move_speed;
	double	rotation_speed;
}				t_player;

typedef struct s_image{
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_minimap {
	void		*tile_img[7];
	int			img_height;
	int			img_width;
}				t_minimap;

typedef struct s_dda{
	double	ray_direction_x;
	double	ray_direction_y;
	int		collision_grid_x;
	int		collision_grid_y;
	int		step_x;
	int		step_y;
	double	side_distance_x;
	double	side_distance_y;
	double	delta_distance_x;
	double	delta_distance_y;
	double	perpendicular_distance;
	bool	is_y_collision;
}				t_dda;

typedef struct s_draw{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_num;
	int		texture_x;
	double	texture_position;
	double	step;
}				t_draw;

typedef struct s_game{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map_info	map_info;
	t_minimap	minimap;
	int			buf[HEIGHT][WIDTH];
	int			**texture;
	t_image		img;
	int			re_buf;
}				t_game;

//error
void		error_exit(int signal);
void		print_error(char *str);
void		exit_with_error(char *message);
int			close_game(t_game *game);
//map
void		free_map_info(t_map_info map_info);
void		free_game(t_game *game);
//setup
void		init_game(t_game *game, int fd);
void		init_minimap(t_game *game);
void		init_texture(t_game *game);
void		init_player(t_game *game);
int			open_cub_file(char *path);
t_map_info	get_map_info(int fd);
//calculate
void		calculate_field_of_view(t_game *game);
void		prepare_calculate_collision_grid(t_game *game, t_dda *dda, int x);
bool		calculate_collision_grid(t_game *game, t_dda *dda);
void		prepare_map_draw(t_draw	*draw, double perpendicular_distance);
void		save_color(t_game *game, t_dda *dda, t_draw *draw, int x);
void		save_ceiling(t_game *game, t_draw *draw, int x);
void		save_floor(t_game *game, t_draw *draw, int x);
//minimap
void		draw_minimap(t_game *game);
//map
void		draw_field_of_view(t_game *game);
int			input_key(int keycode, t_game *game);
// debug
void		print_info(t_map_info info);
void		print_two_dimensional_array(char **array);

#endif