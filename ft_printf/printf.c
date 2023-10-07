/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:06:02 by mosada            #+#    #+#             */
/*   Updated: 2023/10/07 22:55:56 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *fmt, ...)
{
	va_list	ap1;
	va_list	ap2;
	int		d;
	//char	c;
	//char	*s;

	va_start(ap1, fmt);
	va_copy(ap2, ap1);
	while (*fmt)
	{
		if (*fmt == 'd')
		{
			d = va_arg(ap2, int);
			ft_printnum(d);
		}
		fmt++;
	}
	va_end(ap2);
	va_end(ap1);
	return (0);
}

int	main(void)
{
	int	result = ft_printf("%d\n",2,3);
	return 0;
}