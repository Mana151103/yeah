/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:12:21 by mosada            #+#    #+#             */
/*   Updated: 2023/10/07 15:43:58 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (count + 1));
	if (!s)
		return (NULL);
	while (*s1)
		s[i++] = *s1++;
	s[i] = '\0';
	return (s);
}
