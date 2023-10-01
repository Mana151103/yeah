/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:19:05 by mosada            #+#    #+#             */
/*   Updated: 2023/09/30 23:39:10 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
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
	char	*result;
	int		len;
	int		count;

	len = 0;
	count = ft_strlen(s1);
	result = NULL;
	letter = NULL;
	while (charset_chack(*s1, set))
		s1++;
	while (!charset_chack(*s1, set))
	{
		result[len++] = *s1++;
		printf("%c\n",*s1);
		printf("%d\n",len);
	}
	while (charset_chack(s1[count], set))
		count--;
	letter = (char *)malloc(sizeof(char) * (len + 1));
	if (!letter)
		return (NULL);
	ft_strlcpy(letter, result, len + 1);
	letter[len] = '\0';
	return (letter);
}
