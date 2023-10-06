/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:49:21 by mosada            #+#    #+#             */
/*   Updated: 2023/10/04 19:30:32 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (((nbr == (LONG_MAX / 10)) && (*str - '0' >= 8))
			|| (nbr > (LONG_MAX / 10)))
		{
			if (sign == 1)
				return (sign * (int)LONG_MAX);
			else if (sign == -1)
				return (sign * (int)LONG_MIN);
		}
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (sign * (int)nbr);
}
