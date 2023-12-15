/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:44:07 by mosada            #+#    #+#             */
/*   Updated: 2023/10/07 15:14:04 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	while (n--)
	{
		if (*r1 != *r2 || !*r1 || !*r2)
			return (*r1 - *r2);
		r1++;
		r2++;
	}
	return (0);
}
