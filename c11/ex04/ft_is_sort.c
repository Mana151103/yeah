/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:10:26 by mosada            #+#    #+#             */
/*   Updated: 2023/08/29 21:36:53 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag_a;
	int	flag_d;

	i = 0;
	flag_a = 0;
	flag_d = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			flag_a = 1;
		if (f(tab[i], tab[i + 1]) > 0)
			flag_d = 1;
		if (flag_a && flag_d)
			return (0);
		i++;
	}
	return (1);
}
