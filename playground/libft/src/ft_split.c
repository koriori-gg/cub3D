/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:59:43 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *str, char set)
{
	size_t	i;
	size_t	count;
	size_t	start;

	i = 0;
	count = 0;
	if (str == NULL)
		return (count);
	while (str[i] != '\0')
	{
		while ((str[i] != '\0') && (str[i] == set))
			i++;
		start = i;
		while ((str[i] != '\0') && (str[i] != set))
			i++;
		if (i - start != 0)
			count++;
	}
	return (count);
}

static char	**ft_free(char	**ret, size_t count)
{
	while (0 < count)
	{
		count--;
		free(ret[count]);
		ret[count] = NULL;
	}
	free(ret);
	ret = NULL;
	return (ret);
}

static char	**ft_strsplit(char const *str, char set, char **ret, size_t words)
{
	size_t	start;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] != '\0' && count < words)
	{
		while ((str[i] != '\0') && (str[i] == set))
			i++;
		start = i;
		while ((str[i] != '\0') && (str[i] != set))
			i++;
		if (i - start != 0)
		{
			ret[count] = ft_substr(str, start, i - start);
			if (ret[count] == NULL)
				return (ft_free(ret, count));
			count++;
		}
	}
	ret[count] = NULL;
	return (ret);
}

char	**ft_split(char const *str, char set)
{
	size_t	words;
	char	**ret;

	if (!str)
		return (NULL);
	words = ft_wordcount(str, set);
	ret = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	return (ft_strsplit(str, set, ret, words));
}
/*
int	main(void)
{
	char	*str = "/I/have/a/pen//////////I/have/an/apple";
	char	set = '/';
	char **ans = ft_split(str,set);
	int i = 0;
	while(ans[i] != 0)
		printf("ans:%s\n",ans[i++]);
	return (0);
}
*/