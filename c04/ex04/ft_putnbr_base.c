/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 22:49:48 by mosada            #+#    #+#             */
/*   Updated: 2023/08/27 21:43:42 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *src)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 1;
	count = 0;
	while (src[i])
	{
		i++;
		count++;
	}
	i = 0;
	while (i < count - 1)
	{
		while (j < count)
		{
			if (src[i] == src[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_base_len(char *base)
{
	int	count;

	count = 0;
	while (*base)
	{
		count++;
		base++;
	}
	return (count);
}

void	ft_change_number(long nb, int count, char *base)
{
	char	c;

	if (nb / count)
		ft_change_number(nb / count, count, base);
	c = base[nb % count];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		count;
	long	l_nb;

	i = 0;
	l_nb = nbr;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\0')
			return ;
		i++;
	}
	count = ft_base_len(base);
	if (i == 0 || i == 1 || ft_strcmp(base) == 0)
		return ;
	if (l_nb < 0)
	{
		l_nb *= -1;
		write (1, "-", 1);
	}
	ft_change_number(l_nb, count, base);
}
