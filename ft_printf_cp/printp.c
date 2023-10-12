/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:19:29 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 10:34:00 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include <unistd.h>

static void	lchange_to_hexadecimal_up(long v)
{
	char	i;

	if (v / 16)
		lchange_to_hexadecimal_up(v / 16);
	if (v % 16 < 10)
		i = v % 16 + '0';
	else if (v % 16 >= 10)
		i = v % 16 - 10 + 'a';
	write(1, &i, 1);
}

void	putaddress_fd(void *a, int fd)
{
	void	**p;
	
	p = (void **)a;
	write(1, "0x", 2);
	lchange_to_hexadecimal_up((long)&(*p));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	p[] = "12345";
// 	putaddress_fd(p, 1);
// 	puts("");
// 	printf("%p\n",p);
// }