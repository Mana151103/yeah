/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:12:21 by mosada            #+#    #+#             */
/*   Updated: 2023/09/25 22:20:54 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*p;
	int		i;

	i = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (i + 1));
	p = s;
	if (!s)
		return (NULL);
	while (i--)
		*s++ = *s1++;
	*s = '\0';
	return (p);
}
