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

//temp
#define tex_width 64
#define tex_height 64
#define width 960
#define height 540

# define RGB_RED 0xFF0000
# define RGB_GREEN 0x00FF00
# define RGB_BLUE 0x0000FF
# define RGB_WHITE 0xFFFFFF
# define RGB_YELLOW 0xFFFF00

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
	double	position_x;//現在いる座標
	double	position_y;
	double	direction_x;//向いている角度
	double	direction_y;
	double	plane_x;//カメラ
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct	s_image
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_minimap {
	void		*tile_img[7];
	int			img_height;
	int			img_width;
}				t_minimap;

typedef struct	s_dda
{
	double	ray_direction_x;
	double	ray_direction_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		side;
}				t_dda;

typedef struct	s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	int		tex_x;
	double	tex_position;
	double	step;
}				t_draw;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map_info	map_info;
	t_minimap	minimap;
	int			buf[height][width];
	int			**texture;
	t_image		img;
	int			re_buf;
}				t_game;

//error
void		error_exit(int signal);
void		print_error(char *str);
//map
void		free_map_info(t_map_info map_info);
void		free_game(t_game *game);
//utils
void		print_argv(char **argv);
//setup
void		init_game(t_game *game, int fd);
void		init_minimap(t_game *game);
void		init_texture(t_game *game);
//calculate
void		calculate(t_game *game);
void		prepare_dda(t_game *game, t_dda *dda, int x);
int			calculate_dda(t_game *game, t_dda *dda);
void		prepare_map_draw(t_draw	*draw, double perp_wall_dist);
void		save_color(t_game *game, t_dda *dda, t_draw *draw, int x);
void		save_ceiling(t_game *game, t_draw *draw, int x);
void		save_floor(t_game *game, t_draw *draw, int x);
int			char_to_int(char s);
//minimap
void		draw_minimap(t_game *game);
//temp
void		draw(t_game *game);
//move
int			input_key(int keycode, t_game *game);
//close
int			close_game(t_game *game);

void		exit_with_error(char *message);
int			open_cub_file(char *path);
t_map_info	get_map_info(int fd);

// debug
void	print_info(t_map_info info);
void	print_two_dimensional_array(char **array);

#endif