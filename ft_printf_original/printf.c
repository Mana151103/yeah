/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:06:02 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 23:28:25 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

//static void	is_space(char c)
//{
	
//}

static void	is_int(va_list ap, char c)
{
	int	v;

	v = va_arg(ap, int);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(v, 1);
	else if (c == 'c')
		write(1, &v, 1);
	else
		ft_putunbr_fd(v, 1);
}

static void	is_str(va_list ap, char c)
{
	char	*s;

	if (c == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr_fd(s, 1);
	}
	else
	{
		s = va_arg(ap, void *);
		putaddress_fd((void *)s, 1);
	}
}

static void	is_x(va_list ap, char c)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	if (c == 'x')
		change_to_hexadecimal_up(n);
	else
		change_to_hexadecimal_low(n);
}

//static void	is_(va_list ap)
//{
//	char	*s;

//	s = va_arg(ap, char *);
//	ft_putstr_fd(s, 1);
//}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap1;
	int		v;

	v = 0;
	va_start(ap1, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (ft_isdigit(*fmt))
			{
				while (ft_isdigit(*fmt))
				{
					v = v * 10 + (*fmt - '0');
					fmt++;
				}
				while (v > 2)
				{
					write(1, " ", 1);
					v--;
				}
			}
			if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u' || *fmt == 'c')
				is_int(ap1, *fmt);
			else if (*fmt == 's' || *fmt == 'p')
				is_str(ap1, *fmt);
			else if (*fmt == 'x' || *fmt == 'X')
				is_x(ap1, *fmt);
			else
				write(1, fmt, 1);
		}
		else
			write(1, fmt, 1);
		fmt++;
	}
	va_end(ap1);
	return (0);
}
