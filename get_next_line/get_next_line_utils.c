/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:41:59 by mosada            #+#    #+#             */
/*   Updated: 2023/10/15 20:09:00 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

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

//static char	*ft_strjoin(char const *s1, char const *s2, size_t size)
//{
//	char	*a;
//	size_t	count1;

//	if (!s1 || !s2)
//		return (NULL);
//	count1 = ft_strlen(s1);
//	a = (char *)malloc(sizeof(char) * (count1 + size + 1));
//	if (!a)
//		return (NULL);
//	ft_strlcpy(a, s1, count1 + 1);
//	ft_strlcpy(a + count1, s2, size + 1);
//	return (a);
//}

char	*ft_strndup(char const *s, int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, n + 1);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	count1;
	size_t	count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (count1 + count2 + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, count1 + 1);
	ft_strlcpy(a + count1, s2, count2 + 1);
	return (a);
}
