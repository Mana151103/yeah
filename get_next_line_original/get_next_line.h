/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:03:53 by mosada            #+#    #+#             */
/*   Updated: 2023/10/19 18:09:03 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char const *s, size_t n);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*freefunc(char *buffer, char *keep, char *tmp, char *line);

#endif