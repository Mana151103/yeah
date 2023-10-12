/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:06:02 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 10:50:14 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
// #include <unistd.h>
// #include <stdarg.h>

// void	ft_putchar_fd(char c, int fd);
// void	ft_putstr_fd(char *s, int fd);
// void	ft_putnbr_fd(int n, int fd);
// void	change_to_hexadecimal_up(int v);
// void	change_to_hexadecimal_low(int v);
// void	ft_putunbr_fd(int n, int fd);
// void	putaddress_fd(void *a, int fd);

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap1;
	va_list	ap2;
	int		v;
	char	c;
	char	*s;

	va_start(ap1, fmt);
	va_copy(ap2, ap1);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (ft_isdigit(*fmt))
			{
				v = *fmt - '0';
				write(1, " ", v - 1);
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				v = va_arg(ap2, int);
				ft_putnbr_fd(v, 1);
			}
			else if (*fmt == 'u')
			{
				v = va_arg(ap2, int);
				ft_putunbr_fd(v, 1);
			}
			else if (*fmt == 's')
			{
				s = va_arg(ap2, char *);
				ft_putstr_fd(s, 1);
			}
			else if (*fmt == 'c')
			{
				c = va_arg(ap2, int);
				write(1, &c, 1);
			}
			else if (*fmt == 'x')
			{
				v = va_arg(ap2, int);
				change_to_hexadecimal_up(v);
			}
			else if (*fmt == 'X')
			{
				v = va_arg(ap2, int);
				change_to_hexadecimal_low(v);
			}
			else if (*fmt == 'p')
			{
				s = va_arg(ap2, void *);
				putaddress_fd((void *)s, 1);
			}
			else if (*fmt == '%' || *fmt == '+')
				write(1, fmt, 1);
		}
		else
			write(*(char *)fmt);
		fmt++;
	}
	va_end(ap2);
	va_end(ap1);
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	c = 54;
// 	char *null_str = NULL;
// 	int	result = ft_printf("%5chis paragraph is indented", 't');
// 	puts("");
// 	printf("%5chis paragraph is indented", 't');
// 	puts("");
// 	return 0;
// }