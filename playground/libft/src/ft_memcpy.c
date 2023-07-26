/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:20 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
	char buf[50] = "12\04567";
	memcpy(buf+4,buf,4);
	printf("コピー後のbuf文字列→%s\n",buf);

	char buf1[50] = "12\04567";
	ft_memcpy(buf1+4,buf1,4);
	printf("コピー後のbuf文字列→%s\n",buf1);

	char buf2[50] = "";
	ft_memcpy(buf2,buf2,4);
	printf("コピー後のbuf文字列→%s\n",buf2);

	return 0;
}
*/