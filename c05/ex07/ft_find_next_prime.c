/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:28:11 by mosada            #+#    #+#             */
/*   Updated: 2023/08/21 17:44:11 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long	i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (i * i <= nb)
	{
		if (!(nb % i))
			return (ft_find_next_prime(nb + 1));
		i++;
	}
	return (nb);
}
