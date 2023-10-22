/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:33:57 by mosada            #+#    #+#             */
/*   Updated: 2023/10/22 15:51:04 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*readfile(int fd, char *keep)
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
		if (readbytes == 0 && *buffer == '\0' && keep == NULL)
			return (free(buffer), NULL);
		else if (readbytes == 0 && *buffer == '\0' && keep != '\0')
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
	static char	*keep[OPEN_MAX];

	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	keep[fd] = readfile(fd, keep[fd]);
	if (!keep[fd])
		return (NULL);
	is_newline = ft_strchr(keep[fd], '\n');
	if (is_newline)
	{
		line = ft_strndup(keep[fd], is_newline - keep[fd] + 1);
		if (!line)
			return (free(keep[fd]), NULL);
		keep[fd] = update_keep(is_newline, keep[fd], line);
		return (line);
	}
	line = keep[fd];
	keep[fd] = NULL;
	return (line);
}
