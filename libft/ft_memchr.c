/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:00:28 by mosada            #+#    #+#             */
/*   Updated: 2023/09/24 16:53:36 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*i;

	i = (const unsigned char *)s;
	while (n--)
	{
		if (*i == (unsigned char)c)
			return ((void *)i);
		i++;
	}
	return (NULL);
}
