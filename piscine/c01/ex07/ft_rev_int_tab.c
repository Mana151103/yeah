/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:01:02 by mosada            #+#    #+#             */
/*   Updated: 2023/08/15 10:55:07 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	box;

	n = 0;
	while (n < size)
	{
		box = tab[n];
		tab[n] = tab[size - 1];
		tab[size - 1] = box;
		n++;
		size = size - 1;
	}
}
