/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:41:59 by mosada            #+#    #+#             */
/*   Updated: 2023/10/19 10:44:21 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
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

char	*ft_strndup(char const *s, size_t n)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	if (!n)
	{
		
		//result == ""にする？
	}
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[n] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	count1;
	size_t	count2;
	size_t	sum;

	if (!s1)
		return (ft_strdup(s2));
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	sum = count1 + count2;
	a = (char *)malloc(sizeof(char) * (sum + 1));
	if (!a)
		return (NULL);
	a[sum] = '\0';
	while (count2--)
		a[count1 + count2] = s2[count2];
	a[count1] = s2[0];
	if (!count1)
		return (a);
	while (count1--)
		a[count1] = s1[count1];
	a[0] = s1[0];
	return (a);
}
