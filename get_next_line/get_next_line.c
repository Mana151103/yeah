/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:53:20 by mosada            #+#    #+#             */
/*   Updated: 2023/10/22 15:47:42 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_keep(char *is_newline, char *keep, char *line)
{
	char	*tmp;
	size_t	linelen;
	size_t	keeplen;

	if (is_newline[1] == '\0')
		return (free(keep), NULL);
	linelen = ft_strlen(line);
	keeplen = ft_strlen(keep);
	tmp = ft_strndup((is_newline + 1), keeplen - linelen);
	if (!tmp)
		return (free(keep), NULL);
	free(keep);
	keep = tmp;
	return (keep);
}

char	*readfile(int fd, char *keep)
{
	char		*buffer;
	ssize_t		readbytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(keep), NULL);
	while (1)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(buffer), free(keep), NULL);
		buffer[readbytes] = '\0';
		if (readbytes == 0 && *buffer == '\0' && !keep)
			return (free(buffer), NULL);
		else if (readbytes == 0 && *buffer == '\0' && *keep != '\0')
			break ;
		keep = ft_strjoin(keep, buffer);
		if (!keep)
			return (free(buffer), NULL);
		if (ft_strchr(keep, '\n'))
			break ;
	}
	free(buffer);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*is_newline;
	static char	*keep;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	keep = readfile(fd, keep);
	if (!keep)
		return (NULL);
	is_newline = ft_strchr(keep, '\n');
	if (is_newline)
	{
		line = ft_strndup(keep, is_newline - keep + 1);
		if (!line)
			return (free(keep), NULL);
		keep = update_keep(is_newline, keep, line);
		return (line);
	}
	line = keep;
	keep = NULL;
	return (line);
}
