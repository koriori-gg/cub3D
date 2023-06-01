/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:21 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
size_t	ft_strlen_null(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/
/*
size_t  ft_strnlen(const char *str, size_t size)
{
	size_t  i;
	if (size == 0)
		return (0);
	i = 0;
	while(i < size && str[i] != '\0')
		i++;
	return (i);
}
*/
/*
int main(void)
{
	printf("%zu",ft_strlen("abcde\n"));
	printf("%zu",ft_strlen(NULL));
	return 0;
}
*/