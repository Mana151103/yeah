/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:42:07 by mosada            #+#    #+#             */
/*   Updated: 2023/10/19 20:08:12 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 1

static char	*update_tmp(char *is_newline, char *keep, char *line)
{
	char	*tmp;

	tmp = ft_strndup((is_newline + 1), ft_strlen(keep) - ft_strlen(line));
	if (!tmp)
		return (freefunc(NULL, keep, NULL, line));
	free(keep);
	keep = tmp;
	return (keep);
}

static char	*found_newline(char *keep, char *buffer, char *is_newline)
{
	char	*line;

	line = ft_strndup(keep, is_newline - keep + 1);
	if (!line)
		return (freefunc(buffer, keep, NULL, NULL));
	return (line);
}

static char	*readandallocate(char *keep, int fd)
{
	char		*buffer;
	ssize_t		readbytes;
	char		*line;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER_SIZE);
	if (readbytes < 0 || (readbytes == 0 && keep == NULL))
	{
		free(buffer);
		return (NULL);
	}
	else if (readbytes == 0)
	{
		line = ft_strndup(keep, ft_strlen(keep));
		free(keep);
		printf("line = %s\n",line);
		keep = NULL;
		//free(buffer);
		return (line);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*keep = NULL;
	char		*tmp;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	while (1)
	{
		buffer = readandallocate(keep, fd);
		if (!buffer)
			return (NULL);
		tmp = ft_strjoin(keep, buffer);
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
