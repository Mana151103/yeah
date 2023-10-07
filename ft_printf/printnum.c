/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:34:57 by mosada            #+#    #+#             */
/*   Updated: 2023/10/07 21:42:01 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	num = n;
	if (num / 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd('0' + num % 10, fd);
}

void	ft_printnum(int n)
{
	ft_putnbr_fd(n, 1);
}
