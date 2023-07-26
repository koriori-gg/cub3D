/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:31 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (s1 == NULL && len == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	while (i + s2_len <= len && i + s2_len <= s1_len)
	{
		if (ft_strncmp(s1 + i, s2, s2_len) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Bar";
    printf("%s\n",ft_strnstr(largestring,smallstring,7));

	const char *largestring1 = "Foo Bar Baz";
    const char *smallstring1 = "Bar";
    printf("%s",ft_strnstr(largestring1,smallstring1,3));
    return 0;
}
*/