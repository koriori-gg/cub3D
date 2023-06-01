/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:13 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char str[] = "abcdef\0ghij";
	char *p;    
	p = memchr(str, 'h', 12);
	printf("検索文字は文字列の%ld番目\n",p - str);
	printf("%s\n",p);

	char str1[] = "abcdef\0ghij";
	char *p1;    
	p1 = ft_memchr(str1, 'h', 12);
	printf("検索文字は文字列の%ld番目\n",p1 - str1);
	printf("%s\n",p1);

	char str2[] = "abcdef\0ghij";
	char *p2;    
	p2 = ft_memchr(str2, 'k', 12);
	printf("検索文字は文字列の%ld番目\n",p2 - str2);
	printf("%s\n",p2);

	return 0;
}
*/
