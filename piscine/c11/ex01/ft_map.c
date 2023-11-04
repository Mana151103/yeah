/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:10:05 by mosada            #+#    #+#             */
/*   Updated: 2023/08/29 16:29:31 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*box;

	i = 0;
	box = (int *)malloc(sizeof(int) * length);
	if (!box)
		return (NULL);
	while (i < length)
	{
		box[i] = f(tab[i]);
		i++;
	}
	return (box);
}
