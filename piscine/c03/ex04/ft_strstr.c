/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:55:33 by mosada            #+#    #+#             */
/*   Updated: 2023/08/18 11:19:53 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*box;
	char	*pez;

	if (*str == '\0' && *to_find == '\0')
		return (str);
	while (*str)
	{
		box = str;
		pez = to_find;
		while (*pez && (*pez == *box))
		{
			pez++;
			box++;
		}
		if (*pez == '\0')
			return (str);
		str++;
	}
	return (NULL);
}
