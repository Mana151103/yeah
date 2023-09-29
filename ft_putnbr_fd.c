/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:03:59 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 22:27:01 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num / 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd('0' + num % 10, fd);
}
