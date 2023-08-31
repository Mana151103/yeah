/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:28:58 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 17:51:21 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write (1, &a, 1);
}

void	sixteen(unsigned int i)
{
	char	*list;

	list = "0123456789abcdef";
	write (1, &list[i], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (*ptr)
	{
		if (' ' <= *ptr && *ptr <= '~')
			write (1, ptr, 1);
		else
		{
			write (1, "\\", 1);
			sixteen(*ptr / 16);
			sixteen(*ptr % 16);
		}
		ptr++;
	}
}
