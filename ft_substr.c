/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:35:16 by mosada            #+#    #+#             */
/*   Updated: 2023/09/30 21:16:05 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	n;
	unsigned int	size;

	n = ft_strlen(s);
	size = 0;
	if (start >= n)
		return (ft_strdup(""));
	if (len <= n - start)
		size = len;
	else
		size = n - start;
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s + start, size + 1);
	return (a);
}
