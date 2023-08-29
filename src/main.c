/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:30:10 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:31:54 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(0);
}

int	main_loop(t_game *game)
{
	draw_minimap(game);
	calculate_field_of_view(game);
	draw_field_of_view(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		exit_with_error("Usage: ./cub3D maps/OK/subject.cub");
	fd = open_cub_file(argv[1]);
	init_game(&game, fd);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, &input_key, &game);
	mlx_hook(game.win, RED_CLOSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
