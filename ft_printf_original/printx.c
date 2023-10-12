/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:47:31 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 21:58:59 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	change_to_hexadecimal_up(unsigned int v)
{
	char	i;

	if (v / 16)
		change_to_hexadecimal_up(v / 16);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10)
		i = v % 16 - 10 + 'a';
	write(1, &i, 1);
}

void	change_to_hexadecimal_low(unsigned int v)
{
	char	i;

	if (v / 16)
		change_to_hexadecimal_low(v / 16);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10)
		i = v % 16 - 10 + 'A';
	write(1, &i, 1);
}
