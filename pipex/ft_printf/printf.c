/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:06:02 by mosada            #+#    #+#             */
/*   Updated: 2023/10/15 15:56:42 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	is_int(va_list ap, char c)
{
	int		v;
	size_t	len;

	v = va_arg(ap, int);
	len = 0;
	if (c == 'd' || c == 'i')
		len = ft_putnbr(v);
	else
	{
		len++;
		write(STDOUT_FILENO, &v, 1);
	}
	return (len);
}

static size_t	is_str(va_list ap, char c)
{
	char	*s;
	size_t	len;

	len = 0;
	if (c == 's')
	{
		s = va_arg(ap, char *);
		len = ft_putstr(s);
	}
	else
	{
		s = va_arg(ap, void *);
		len = putaddress((void *)s);
	}
	return (len);
}

static size_t	readfmt(char c, va_list ap)
{
	size_t	len;

	len = 0;
	if (c == 'd' || c == 'i' || c == 'c')
		len = is_int(ap, c);
	else if (c == 'u')
		len = is_uint(ap);
	else if (c == 's' || c == 'p')
		len = is_str(ap, c);
	else if (c == 'x' || c == 'X')
		len = is_x(ap, c);
	else
	{
		write(STDOUT_FILENO, &c, 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	sum;

	sum = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		sum = 0;
		if (*fmt == '%')
		{
			fmt++;
			sum += readfmt(*fmt, ap);
		}
		else
		{
			write(STDOUT_FILENO, fmt, 1);
			sum++;
		}
		fmt++;
	}
	return (va_end(ap), sum);
}
