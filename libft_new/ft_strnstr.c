/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:40:48 by mosada            #+#    #+#             */
/*   Updated: 2023/10/06 18:58:58 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		count;
	const char	*h;
	const char	*n;

	count = 0;
	if (!*needle)
		return ((char *)haystack);
	else if (!len || *haystack == '\0')
		return (NULL);
	while ((count + ft_strlen(needle)) <= len)
	{
		h = haystack;
		n = needle;
		while (*n && (*n == *h))
		{
			n++;
			h++;
		}
		if (!*n)
			return ((char *)haystack);
		count++;
		haystack++;
	}
	return (NULL);
}
