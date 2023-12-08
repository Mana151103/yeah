/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:22:48 by mosada            #+#    #+#             */
/*   Updated: 2023/12/08 17:05:45 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strcat(char *dest, char *src)
{
	char	*result;
	size_t	d_len;
	size_t	s_len;
	int		i;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	result = malloc(sizeof(char) * (d_len + s_len + 1));
	if (!result)
		return (NULL);
	while (dest[i])
	{
		result[i] = dest[i];
		i++;
	}
	while (*src)
	{
		result[i] = *src;
		i++;
		src++;
	}
	result[i] = 0;
	return (result);
}
