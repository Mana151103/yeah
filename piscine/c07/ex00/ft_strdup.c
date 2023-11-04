/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:39:52 by mosada            #+#    #+#             */
/*   Updated: 2023/08/24 01:04:05 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*address1;
	char	*address2;
	char	*letter;
	int		n;
	int		i;

	n = 0;
	i = 0;
	address2 = src;
	while (*src)
	{
		n++;
		src++;
	}
	src = address2;
	address1 = (char *)malloc(sizeof(char) * (n + 1));
	letter = address1;
	while (i < n)
	{
		*address1++ = *src++;
		i++;
	}
	*address1 = '\0';
	return (letter);
}
