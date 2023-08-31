/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:47:02 by mosada            #+#    #+#             */
/*   Updated: 2023/08/14 12:50:09 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	main(void)
{
	int	a = 13;
	int	b = 4;
	int	div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("div = %d,mod = %d",div,mod);
	return 0;
}
