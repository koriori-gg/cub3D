/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:33 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = (char)c;
	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void)
{
	char test[20] = "abcdefghijk";
	char *p;
	p = ft_strrchr(test,'g');
	printf("myl:%s\n",p);

	char test1[20] = "abcdefghijk";
	char *p1;
	p1 = strrchr(test1,'g');
	printf("lib:%s\n",p1);
	return 0;
}
*/