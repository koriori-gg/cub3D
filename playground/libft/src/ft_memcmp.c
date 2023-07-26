/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:16 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] == str2[i]) && i + 1 < n)
		i++;
	return (str1[i] - str2[i]);
}
/*
int main(void)
{
	int	len = 30;
	char *str = calloc(30, sizeof(char));
	char *cmp = calloc(30, sizeof(char));
	for (int i = 0; i <= len; i++)
	{
		cmp = strndup(str, i);
		printf("%d\n",ft_memcmp(str, cmp, i));
		printf("%d\n",ft_memcmp(str, cmp, len));
		free(cmp);
	}
}
*/
/*
int main(void)
{
	size_t n1 =4;
	char s1[]="ab";
	char s2[]="abcd";
	printf("自作:%d\n",ft_memcmp(s1,s2,n1));
	printf("lib:%d\n",memcmp(s1,s2,n1));

	size_t n10 =4;
	char s10[]="ab";
	char s20[]="aBcd";
	printf("自作:%d\n",ft_memcmp(s10,s20,n10));
	printf("lib:%d\n",memcmp(s10,s20,n10));
	return 0;
}
*/