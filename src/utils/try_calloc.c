/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:56:27 by ihashimo          #+#    #+#             */
/*   Updated: 2023/08/29 19:56:28 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*try_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(n, size);
	if (!ptr)
		exit_with_error("Memory allocation error");
	return (ptr);
}
