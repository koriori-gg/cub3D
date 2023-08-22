/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:37 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && ft_strchr((char *)set, s1[i]) != NULL)
		i++;
	len = ft_strlen(s1);
	if (i < len)
	{
		while (ft_strchr((char *)set, s1[len - 1]) != NULL)
			len--;
	}
	return (ft_substr(s1, i, len - i));
}
/*
int main(void)
{
	char *ans;
	char s1[] = "namhiamuhigi-nahimagomhie-namatanagoh";
	char set[] = "hi";
	ans =ft_strtrim(s1, set);
	printf("%s",ans);
	return 0;
}
*/