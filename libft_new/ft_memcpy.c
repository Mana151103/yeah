/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:37:20 by mosada            #+#    #+#             */
/*   Updated: 2023/10/06 18:02:47 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)dst;
	if (!dst && !src)
		return (dst);
	while (n--)
		*i++ = *(unsigned char *)src++;
	return (dst);
}
