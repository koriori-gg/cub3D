#include "cub3d.h"

static void	*ft_xpm_to_image(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin("textures/5/", str);
	if (!path)
		exit_with_error("calloc error");
	img = try_mlx_xpm_file_to_image(game->mlx, path, &game->minimap.img_width,
			&game->minimap.img_height);
	free(path);
	if (!img)
		exit_with_error("Invalid file extension");
	return (img);
}

void	init_minimap(t_game *game)
{
	game->minimap.img_width = 5;
	game->minimap.img_height = 5;
	game->minimap.tile_img[0] = ft_xpm_to_image(game, "floor.xpm");
	game->minimap.tile_img[1] = ft_xpm_to_image(game, "green.xpm");
	game->minimap.tile_img[2] = ft_xpm_to_image(game, "player.xpm");
}
