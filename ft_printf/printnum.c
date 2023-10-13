/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:34:57 by mosada            #+#    #+#             */
/*   Updated: 2023/10/13 21:19:41 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static void	ft_putchar_fd(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

size_t	ft_putnbr(int n)
{
	long	num;
	long	l;
	size_t	len;

	num = n;
	l = 0;
	len = 0;
	if (num < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		num *= -1;
		len++;
	}
	l = num;
	while (l / 10)
	{
		len++;
		l /= 10;
	}
	if (num / 10)
		ft_putnbr(num / 10);
	ft_putchar_fd('0' + num % 10);
	return (len + 1);
}

size_t	ft_putunbr(unsigned int n)
{
	unsigned int	num;
	size_t			len;

	num = n;
	len = 0;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	if (num / 10)
		ft_putunbr(num / 10);
	ft_putchar_fd('0' + num % 10);
	return (len + 1);
}

size_t	is_uint(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	return (ft_putunbr(u));
}
