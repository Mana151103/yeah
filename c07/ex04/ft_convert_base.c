/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:26:25 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 10:44:47 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	baselen(char *base)
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

int	*ft_basecheck(char *base)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 1;
	count = baselen(base);
	if (count == 1 || count == 0)
		return (NULL);
	while (i < count - 1)
	{
		while (j < count)
		{
			if (base[i] == base[j])
				return (NULL);
			if ((9 <= base[i] && base[i] <= 13) || base[i] == '+'
				|| base[i] == '-' || base[i] == ' ')
				return (NULL);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (base);
}

int	check_same(char *str, char *base, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (*str == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	sign;
	int	length;

	nbr = 0;
	sign = 1;
	length = baselen(base);
	if (ft_basecheck(base) == NULL || base[length - 1] == ' '
		|| (9 <= base[length - 1] && base[length - 1] <= 13))
		return (0);
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (check_same(str, base, length) != -1)
	{
		nbr = nbr * length + check_same(str, base, length);
		str++;
	}
	return (sign * nbr);
}

void	ft_change_number(long nb, int count, char *base)
{
	char	c;

	if (nb < 0)
	{
		nb *= -1;
		write (1, "-", 1);
	}
	if (nb / count)
		ft_change_number(nb / count, count, base);
	c = base[nb % count];
	write(1, &c, 1);
}
