/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:19:05 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 21:19:19 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset_chack(char s, char const *c)
{
	while (*c)
	{	
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	size_t	count;
	int		size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	count = ft_strlen(s1) - 1;
	while (charset_chack(s1[i], set))
		i++;
	while (charset_chack(s1[count], set))
		count--;
	if (count < 0)
		size = i;
	else
		size = count - i;
	result = (char *)malloc(sizeof(char) * (size + 2));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + i, size + 2);
	return (result);
}
