/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:47:31 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 10:30:35 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include <unistd.h>
//#include <stdlib.h>

void	change_to_hexadecimal_up(int v)
{
	char	i;
	long	lv;

	lv = v;
	if (lv / 16)
		change_to_hexadecimal_up(lv / 16);
	if (lv % 16 < 10)
		i = lv % 16 + '0';
	else if (lv % 16 >= 10)
		i = lv % 16 - 10 + 'a';
	write(1, &i, 1);
}

void	change_to_hexadecimal_low(int v)
{
	char	i;
	long	lv;
	
	lv = v;
	if (lv / 16)
		change_to_hexadecimal_low(lv / 16);
	if (lv % 16 < 10)
		i = lv % 16 + '0';
	else if (lv % 16 >= 10)
		i = lv % 16 - 10 + 'A';
	write(1, &i, 1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	change_to_hexadecimal_low(255);
// 	puts("");
// 	printf("%X\n",255);
// 	return 0;
// }