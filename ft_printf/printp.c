/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:19:29 by mosada            #+#    #+#             */
/*   Updated: 2023/10/13 20:40:34 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	lchange_to_hexadecimal_up(size_t v)
{
	char	i;
	size_t	l;
	size_t	len;

	l = v;
	len = 0;
	while (l / 16)
	{
		len++;
		l /= 16;
	}
	if (v / 16)
		lchange_to_hexadecimal_up(v / 16);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10)
		i = v % 16 - 10 + 'a';
	write(STDOUT_FILENO, &i, 1);
	return (len + 3);
}

size_t	putaddress(void *a)
{
	void	**p;
	size_t	len;

	len = 0;
	p = (void **)a;
	write(STDOUT_FILENO, "0x", 2);
	return (lchange_to_hexadecimal_up((size_t) &(*p)));
}
