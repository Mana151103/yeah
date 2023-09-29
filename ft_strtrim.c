/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:19:05 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 16:18:02 by mosada           ###   ########.fr       */
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
	char	*letter;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	letter = (char *)malloc(sizeof(char) * (len + 1));
	if (!letter)
		return (NULL);
	while (*s1)
	{
		if (!charset_chack(*s1, set))
			letter[i++] = *s1++;
		else if (charset_chack(*s1, set))
			s1++;
	}
	letter[i] = '\0';
	return (letter);
}
