/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:47:31 by mosada            #+#    #+#             */
/*   Updated: 2023/10/13 21:19:15 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	change_to_hexadecimal_up(unsigned int v)
{
	char			i;
	unsigned int	u;
	size_t			len;

	u = v;
	len = 0;
	while (u / 16)
	{
		len++;
		u /= 16;
	}
	if (v / 16)
		change_to_hexadecimal_up(v / 16);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10)
		i = v % 16 - 10 + 'a';
	write(STDOUT_FILENO, &i, 1);
	return (len + 1);
}

size_t	change_to_hexadecimal_low(unsigned int v)
{
	char			i;
	unsigned int	u;
	size_t			len;

	u = v;
	len = 0;
	while (u / 16)
	{
		len++;
		u /= 16;
	}
	if (v / 16)
		change_to_hexadecimal_low(v / 16);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10)
		i = v % 16 - 10 + 'A';
	write(STDOUT_FILENO, &i, 1);
	return (len + 1);
}

size_t	is_x(va_list ap, char c)
{
	unsigned int	n;
	size_t			len;

	len = 0;
	n = va_arg(ap, unsigned int);
	if (c == 'x')
		len = change_to_hexadecimal_up(n);
	else
		len = change_to_hexadecimal_low(n);
	return (len);
}
