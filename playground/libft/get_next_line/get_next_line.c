/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:23:04 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 13:27:01 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *save, char *temp)
{
	char	*res;

	res = ft_strjoin(save, temp);
	free(save);
	return (res);
}

char	*ft_read_file(int fd, char *save)
{
	char	*temp;
	int		bytes;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		save = ft_free(save, temp);
		if (!save)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (save);
}

char	*ft_get_line(char *save)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = save[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_line(char *save)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rest = (char *)ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		rest[j++] = save[i++];
	rest[j] = '\0';
	free(save);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save_line(save);
	return (line);
}
