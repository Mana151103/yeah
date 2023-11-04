/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:47:31 by mosada            #+#    #+#             */
/*   Updated: 2023/10/15 16:18:52 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	change_to_hexadecimal(unsigned int v, bool is_lower)
{
	char			i;
	unsigned int	u;
	size_t			len;

	u = v;
	len = 1;
	while (u / 16)
	{
		len++;
		u /= 16;
	}
	if (v / 16)
		change_to_hexadecimal(v / 16, is_lower);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10 && is_lower)
		i = v % 16 - 10 + 'A';
	else if (v % 16 >= 10 && !is_lower)
		i = v % 16 - 10 + 'a';
	write(STDOUT_FILENO, &i, 1);
	return (len);
}

size_t	is_x(va_list ap, char c)
{
	unsigned int	n;
	size_t			len;

	len = 0;
	n = va_arg(ap, unsigned int);
	len = change_to_hexadecimal(n, c == 'x');
	return (len);
}
