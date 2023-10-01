/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:40:48 by mosada            #+#    #+#             */
/*   Updated: 2023/10/01 20:46:19 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		count;
	size_t		nlen;
	const char	*h;
	const char	*n;

	count = 0;
	if (!*needle)
		return ((char *)haystack);
	else if (!haystack || !len)
		return (NULL);
	else if(!*haystack)
		return (NULL);
	nlen = ft_strlen(needle);
	while ((count + nlen) <= len)
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
