/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:42:07 by mosada            #+#    #+#             */
/*   Updated: 2023/10/15 21:41:59 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char const *s, int n);
char	*ft_strchr(char *s, char c);
char	*ft_bzero(char *s, size_t n);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*p;
	static char	*keep;
	int			is_line;
	int			is_first;
	ssize_t		i;
	ssize_t		is_newline;
	ssize_t		readbytes;
	ssize_t		sum;

	i = 0;
	sum = 0;
	is_newline = 0;
	is_first = 1;
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (1)
	{
		is_line = 0;
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (NULL);
		if (readbytes == 0)
			return (NULL);
		sum += readbytes;
		while (i < sum)
		{
			if (buffer[i] == '\n')
			{
				is_line = 1;
				is_newline = i;
			}
			i++;
		}
		p = ft_strchr(buffer, '\n');
		if (is_line)
		{
			ft_strjoin(keep, p);
			line = ft_strndup(keep, (is_newline + 1));
			if (!line)
				return (NULL);
			keep = buffer + is_newline;
			free(buffer);
			return (line);
		}
		else
			ft_strjoin(keep, (buffer + sum - readbytes));
	}
	free(buffer);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int	main(void)
{
	int	fd = open("sample.txt", O_RDONLY);
	char	*line;

    while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}
