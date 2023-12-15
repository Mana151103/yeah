/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:18:54 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 21:21:25 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	intcount(long long n)
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
	char		*result;
	size_t		count;
	bool		is_negative;
	long long	num;

	num = n;
	count = intcount(num);
	is_negative = (num < 0);
	result = (char *)malloc(sizeof(char) * (count + is_negative + 1));
	if (!result)
		return (NULL);
	if (is_negative)
	{
		result[0] = '-';
		num *= -1;
	}
	result[count + is_negative] = '\0';
	while (count --)
	{
		result[count + is_negative] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}
