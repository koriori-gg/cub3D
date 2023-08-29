#include "cub3d.h"

static void	*ft_xpm_to_image(t_game *game, char *str)
{
	char	*path;
	void	*img;

	path = ft_strjoin("textures/minimap/", str);
	if (!path)
		exit_with_error("calloc error");
	img = try_mlx_xpm_file_to_image(game->mlx, path, &game->minimap.width,
			&game->minimap.height);
	free(path);
	if (!img)
		exit_with_error("Invalid file extension");
	return (img);
}

void	init_minimap(t_game *game)
{
	game->minimap.width = 5;
	game->minimap.height = 5;
	game->minimap.grid_img[FLOOR] = ft_xpm_to_image(game, "floor.xpm");
	game->minimap.grid_img[WALL] = ft_xpm_to_image(game, "wall.xpm");
	game->minimap.grid_img[PLAYER] = ft_xpm_to_image(game, "player.xpm");
}
