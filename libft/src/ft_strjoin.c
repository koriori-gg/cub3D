/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:07 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 11:34:15 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ret;

	if (s1 == NULL && s2)
		s1 = "";
	else if (s1 && s2 == NULL)
		s2 = "";
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
		ret[len++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		ret[len++] = s2[j++];
	ret[len] = '\0';
	return (ret);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ret;

	if (s1 == NULL && s2)
		s1 = "";
	else if (s1 && s2 == NULL)
		s2 = "";
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
		ret[len++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		ret[len++] = s2[j++];
	ret[len] = '\0';
	return (ret);
}
*/
/*
int main(void)
{
	printf("%s\n",ft_strjoin("ss","\0"));
	printf("%s\n",ft_strjoin("\0","\0"));
	printf("%s\n",ft_strjoin("\0","ss"));
}
*/
/*
int	main(void)
{
	char s1[] = "konnitiha";
	char s2[] = "-konbanwa";
	printf("%s",ft_strjoin(s1, s2)s);
	return (0);
}
*/