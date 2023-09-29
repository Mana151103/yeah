/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:18:54 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 17:48:10 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intcount(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		is_negative;

	count = intcount(n);
	is_negative = (n < 0);
	result = (char *)malloc(sizeof(char) * count + 1);
	if (!result)
		return (NULL);
	if (is_negative)
	{
		result[0] = '-';
		n *= -1;
	}
	result[count] = '\0';
	while (count -- > 0)
	{
		result[count + is_negative] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
