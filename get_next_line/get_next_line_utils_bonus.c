/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:34:58 by mosada            #+#    #+#             */
/*   Updated: 2023/10/28 19:09:59 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[n] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	count1;
	size_t	count2;
	size_t	sum;

	count2 = ft_strlen(s2);
	if (!s1)
		return (ft_strndup(s2, count2));
	count1 = ft_strlen(s1);
	sum = count1 + count2;
	a = (char *)malloc(sizeof(char) * (sum + 1));
	if (!a)
		return (free((void *)s1), NULL);
	a[sum] = '\0';
	while (count2--)
		a[count1 + count2] = s2[count2];
	a[count1] = s2[0];
	if (!count1)
		return (a);
	while (count1--)
		a[count1] = s1[count1];
	a[0] = s1[0];
	free((void *)s1);
	return (a);
}
