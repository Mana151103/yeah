/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:25:43 by mosada            #+#    #+#             */
/*   Updated: 2023/10/01 17:33:32 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*a;
	long long	c;
	long long	s;

	c = count;
	s = size;
	if ((count * size) >= SIZE_T_MAX)
		return (NULL);
	a = (char *)malloc(size * count);
	if (!a)
		return (NULL);
	return (ft_memset(a, 0, count));
}
