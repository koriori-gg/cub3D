#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
// # include "mlx_int.h"
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
#define map_width 24
#define map_height 24
// #define width 640
// #define height 480
// #define width 1920
// #define height 1080
#define width 960
#define height 540 //mapから読み取り or ディスプレイサイズに合わせる必要あり

# define x_axis 0
# define y_axis 1

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

typedef struct s_map {
	char			*row;
	int				y;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}				t_rgb;

typedef struct s_mapinfo {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_rgb	*floor_color;
	t_rgb	*ceiling_color;
	t_map	*map;
}				t_mapinfo;

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
	t_mapinfo	*map_info;
	t_minimap	minimap;
	char 		**world_map;
//02
	int			buf[height][width];
	int			**texture;
	t_image		img;
	int			re_buf;
}				t_game;

//validate_argument and map
void		validate_argument(int argc, char **argv);
void		validate_map(char **argv);
//error
void		error_exit(int signal);
void		print_error(char *str);
//map
t_map		*ft_mapnew(char *str, size_t y);
int			ft_mapsize(t_map *map);
void		ft_mapadd_back(t_map **map, t_map *new);
void		ft_free_map(t_map *map);
t_map		*mapdup(t_map *map);
t_mapinfo	*init_mapinfo(char **argv);
void		free_map_info(t_mapinfo *map_info);
bool		is_elements_info(char *str);
//utils
void		print_argv(char **argv);
void		print_map(t_map *map);
void		print_map_info(t_mapinfo *map_info);
//setup
void		init_struct(t_game *game, char **argv);
void		*ft_xpm_to_image(t_game *game, char *str);
//calculate
void		calculate(t_game *game);
void		prepare_dda(t_game *game, t_dda *dda, int x);
int			calculate_dda(t_game *game, t_dda *dda);
void		prepare_map_draw(t_draw	*draw, double perp_wall_dist);
void		save_color(t_game *game, t_dda *dda, t_draw *draw, int x);
int			char_to_int(char s);
//minimap
void		draw_map(t_game *game);
//temp
void		draw(t_game *game);

#endif