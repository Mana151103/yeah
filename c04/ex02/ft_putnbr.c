/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:55:17 by mosada            #+#    #+#             */
/*   Updated: 2023/08/20 10:57:56 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char a)
{
	write (1, &a, 1);
}

void	ft_putnbr(int nb)
{
	long	l_nb;

	l_nb = nb;
	if (l_nb < 0)
	{
		l_nb *= -1;
		ft_putchar ('-');
	}
	if (l_nb / 10)
		ft_putnbr(l_nb / 10);
	ft_putchar('0' + l_nb % 10);
}
