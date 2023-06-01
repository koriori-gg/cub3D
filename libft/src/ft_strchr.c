/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:52 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 13:25:23 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char)c;
	if (!s && cc)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int main(void)
{
	char test[20] = "abcdefghijk";
	char *p;
	p = ft_strchr(test,'g');
	printf("myl:%s\n",p);

	char test1[20] = "abcdefghijk";
	char *p1;
	p1 = strchr(test1,'g');
	printf("lib:%s\n",p1);
	return 0;
}
*/