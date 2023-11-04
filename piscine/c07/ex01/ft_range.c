/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:38:29 by mosada            #+#    #+#             */
/*   Updated: 2023/08/22 19:23:03 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	*adress;
	int	number;
	int	n;

	n = 0;
	number = min;
	if (min >= max)
		return (NULL);
	while (min < max)
	{
		n++;
		min++;
	}
	array = (int *)malloc((sizeof(int) * n));
	adress = array;
	while (number < max)
		*array++ = number++;
	return (adress);
}
