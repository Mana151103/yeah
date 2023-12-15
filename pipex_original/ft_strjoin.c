/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:18:42 by mosada            #+#    #+#             */
/*   Updated: 2023/12/08 20:20:59 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	count1;
	size_t	count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (count1 + count2 + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, count1 + 1);
	ft_strlcpy(a + count1, s2, count2 + 1);
	return (a);
}
