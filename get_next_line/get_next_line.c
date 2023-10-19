/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:42:07 by mosada            #+#    #+#             */
/*   Updated: 2023/10/19 10:32:57 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//20bytesからコンパイルエラーがおこらない

#define BUFFER_SIZE 1

char	*freefunc(char *buffer, char *keep, char *tmp, char *line)
{
	if (buffer)
		free(buffer);
	if (tmp)
		free(tmp);
	if (line)
		free(line);
	if (keep)
		free(keep);
	return (NULL);
}

char	*update_tmp(char *is_newline, char *keep, char *line)
{
	char	*tmp;

	tmp = ft_strndup((is_newline + 1), ft_strlen(keep) - ft_strlen(line));
	if (!tmp)
		return (freefunc(NULL, keep, NULL, line));
	free(keep);
	keep = tmp;
	return (keep);
}

char	*noread(char *keep, char *buffer)
{
	size_t	keeplen;
	char	*line;

	free(buffer);
	keeplen = ft_strlen(keep);
	if (keeplen)
	{
		line = ft_strndup(keep, keeplen);
		if (!line)
			return (freefunc(NULL, keep, NULL, NULL));
		free(keep);
		return (line);
	}
	return (NULL);
}

char	*found_newline(char *keep, char *buffer, char *is_newline)
{
	char	*line;
	
	line = ft_strndup(keep, is_newline - keep + 1);
	if (!line)
		return (freefunc(buffer, keep, NULL, NULL));
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*keep = NULL;
	char		*tmp;
	ssize_t		readbytes;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	while (1)
	{
		buffer = (char *)malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
		{
			line = noread(keep, buffer);
			if (!line)
				return (NULL);
			return (line);
		}
		tmp = ft_strjoin(keep, buffer);
		// printf("keep = %s\n",keep);
		free(keep);
		if (!tmp)
			return (freefunc(buffer, NULL, NULL, NULL));
		keep = tmp;
		if (ft_strchr(keep, '\n'))
        {
			line = found_newline(keep, buffer, ft_strchr(keep, '\n'));
			if (!line)
				return (freefunc(buffer, keep, NULL, NULL));
			keep = update_tmp(ft_strchr(keep, '\n'), keep, line);
			if (!keep)
				return (freefunc(buffer, NULL, tmp, line));
			free(buffer);
			return (line);
        }
        free(buffer);
	}
}
