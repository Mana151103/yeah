/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:27:52 by mosada            #+#    #+#             */
/*   Updated: 2023/08/26 11:37:21 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *letter)
{
	while (*letter)
		write(1, letter++, 1);
}

void	ft_putchar(char abc)
{
	write (1, &abc, 1);
}

void	ft_putnbr(int nb)
{
	long	l_nb;

	l_nb = nb;
	if (l_nb < 0)
	{
		write(1, "-", 1);
		l_nb *= -1;
	}
	if (l_nb / 10)
		ft_putnbr(l_nb / 10);
	ft_putchar('0' + l_nb % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write (1, "\n", 1);
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		ft_putstr(par[i].copy);
		write (1, "\n", 1);
		i++;
	}
}
