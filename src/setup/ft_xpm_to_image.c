#include "cub3d.h"

void	*ft_xpm_to_image(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin("textures/4/", str);//path error
	img = mlx_xpm_file_to_image(game->mlx, path, &game->minimap.img_width,
			&game->minimap.img_height);
	free(path);
	if (!img)
		error_exit(IMAGE_ERROR);
	return (img);
}
