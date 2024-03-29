/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:30:08 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 14:30:08 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*try_mlx_init(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		exit_with_error("mlx error");
	return (mlx);
}

void	*try_mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*win;

	win = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (!win)
		exit_with_error("mlx error");
	return (win);
}

void	*try_mlx_new_image(void *mlx_ptr, int width, int height)
{
	void	*image;

	image = mlx_new_image(mlx_ptr, width, height);
	if (!image)
		exit_with_error("mlx error");
	return (image);
}

void	*try_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
	int *width, int *height)
{
	void	*image;

	image = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (!image)
		exit_with_error("The path for the .xpm image is incorrect");
	return (image);
}

char	*try_mlx_get_data_addr(void *image_ptr, int *bits_per_pixel,
	int *size_line, int *endian)
{
	char	*data;

	data = mlx_get_data_addr(image_ptr, bits_per_pixel, size_line, endian);
	if (!data)
		exit_with_error("mlx error");
	return (data);
}
