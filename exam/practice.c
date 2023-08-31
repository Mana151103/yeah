/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:44:00 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 21:19:47 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	count (int nb)
{
	int	count = 1;
	
	if (nb == 0)
		return (1);
	while (nb / 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char	*box;
	int		is_negative;
	int		c = count(nb);

	is_negative = (nb < 0);
	box = (char *)malloc(sizeof(char) * (c + is_negative + 1));
	if (!box)
		return (NULL);
	if (is_negative)
	{
		box[0] = '-';
		nb *= -1;
	}
	box[c] = '\0';
	while (c-- > 0)
	{
		box[c + is_negative] = nb % 10 + '0';
		nb /= 10;
	}
	return(box);
}

int	main(void)
{
	printf("%s\n", ft_itoa(-123345345));
	return (0);
}