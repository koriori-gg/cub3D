/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:48:40 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	if (size > SIZE_MAX / n)
		return (NULL);
	ret = malloc(size * n);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * n);
	return (ret);
}
/*
int	main(void)
{
	int test = 10;
	int* values = ft_calloc(10, sizeof(int));
	for( int i = 0; i < test; ++i)
	{
        printf("%d ", values[i]);
    }
    printf("\n");
	for( int i = 0; i < test; ++i)
	{
        values[i] = i;
    }
	for( int i = 0; i < test; ++i)
	{
        printf("%d ", values[i]);
    }
	printf("\n");
	values = ft_calloc(10, sizeof(int));
	for( int i = 0; i < test; ++i)
	{
        printf("%d ", values[i]);
    }
    printf("\n");
	return 0;
}
*/