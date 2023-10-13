/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:32:12 by mosada            #+#    #+#             */
/*   Updated: 2023/10/13 20:40:11 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (6);
	while (s[len])
		len++;
	return (len);
}

size_t	ft_putstr(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (len);
	}
	while (*s)
		write(STDOUT_FILENO, s++, 1);
	return (len);
}
