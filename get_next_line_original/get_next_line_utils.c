/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:41:59 by mosada            #+#    #+#             */
/*   Updated: 2023/10/15 21:40:09 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_bzero(char *s, size_t n)
{
	while (n--)
		s[n] = '\0';
	return (s);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strndup(char const *s, int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, n + 1);
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (count + 1));
	if (!s)
		return (NULL);
	while (*s1)
		s[i++] = *s1++;
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	count1;
	size_t	count2;

	if (!s1 || !s2)
		return (ft_strdup(s2));
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (count1 + count2 + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, count1 + 1);
	ft_strlcpy(a + count1, s2, count2 + 1);
	return (a);
}
