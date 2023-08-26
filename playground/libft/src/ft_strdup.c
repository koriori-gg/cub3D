/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:54 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		size;
	char		*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)src, size + 1);
	return (dest);
}
/*
int main(void)
{
	char src[]="abcde";
	printf("src:%s\n",src);
	printf("adress:%p\n",&src);
	printf("destad:%p\n",ft_strdup(src));
	char *a=ft_strdup(src);
	printf("dest:%s\n",a);
	return(0);
}
*/