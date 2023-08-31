/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:40:55 by mosada            #+#    #+#             */
/*   Updated: 2023/08/15 11:21:21 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	n;
	int	box;

	n = 0;
	while (size >= 2)
	{
		while ((n + 1) <= size - 1)
		{
			if (tab[n] > tab [n + 1])
			{
				box = tab[n];
				tab[n] = tab[n + 1];
				tab[n + 1] = box;
			}
			n++;
		}
		n = 0;
		size = size - 1;
	}
}
