/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:41:34 by mosada            #+#    #+#             */
/*   Updated: 2023/09/25 20:11:41 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		t;
	size_t	dstlen;

	i = 0;
	t = 0;
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	while (dst[i])
		i++;
	while ((dstsize - dstlen - 1) > 0 && src[t] != '\0')
	{
		dst[i++] = src[t++];
		dstsize--;
	}
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}
