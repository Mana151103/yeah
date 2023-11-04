/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:42:47 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 15:16:03 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

void	ft_putnbr(int nb)
{
	long	l_nb;
	char	c;

	l_nb = nb;
	if (l_nb < 0)
	{
		l_nb *= -1;
		write(1, "-", 1);
	}
	if (l_nb / 10)
		ft_putnbr(l_nb / 10);
	c = '0' + l_nb % 10;
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

int	operator(int s1, int s2, char s3)
{
	if (s3 == '+')
		return (s1 + s2);
	else if (s3 == '-')
		return (s1 - s2);
	else if (s3 == '*')
		return (s1 * s2);
	else if (s3 == '/')
		return (s1 / s2);
	else if (s3 == '%')
		return (s1 % s2);
	else
		return (0);
}
