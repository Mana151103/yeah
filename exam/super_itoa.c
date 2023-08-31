/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:04:22 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 19:26:05 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	num_of_digits(int nbr)
{
	int	digits;

	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int nbr)
{
	char	*ret;
	int		is_negative;
	int		digits;

	is_negative = (nbr < 0);
	digits = num_of_digits(nbr);
	ret = malloc(sizeof(char) * (digits + is_negative + 1));
	if (is_negative)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	ret[digits] = '\0';
	while (digits-- > 0)
	{
		ret[digits + is_negative] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ret);
}



int	main(void)
{
	printf("%s\n", ft_itoa(-123345345));
	return (0);
}
