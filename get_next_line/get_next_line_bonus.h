/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:35:35 by mosada            #+#    #+#             */
/*   Updated: 2023/10/21 19:57:47 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char const *s, size_t n);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
