/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:25:43 by mosada            #+#    #+#             */
/*   Updated: 2023/10/07 18:28:30 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;

	if (!count || !size)
	{
		a = malloc(1);
		if (!a)
			return (NULL);
		return (ft_memset(a, 0, 1));
	}
	if (size >= (SIZE_T_MAX / count))
		return (NULL);
	a = malloc(count * size);
	if (!a)
		return (NULL);
	return (ft_memset(a, 0, count * size));
}
