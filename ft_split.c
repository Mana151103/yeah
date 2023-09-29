/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:46:01 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 11:04:37 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charset_chack(char s, char *c)
{
	while (*c)
	{	if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

int	count_words(char const *s, char *c)
{
	int	flag;
	int	count;

	flag = 1;
	count = 0;
	while (*s)
	{
		if (charset_chack(*s, c))
			flag = 1;
		if (flag == 1 && !charset_chack(*s, c))
		{
			count++;
			flag = 0;
		}
		s++;
	}
	return (count);
}

char	*likestrdup(char const *s, char **letter, int count, int i)
{
	int	n;
	
	n = 0;
	letter[i] = (char *)malloc(sizeof(char) * (count + 1));
	if (!letter[i])
	{
		while (i)
		{
			free (letter[i]);
			i--;
		}
		free (letter);
		return (NULL);
	}
	s -= count;
	while (n < count)
		letter[i][n++] = *s++;
	letter[i][n] = '\0';
	return (letter[i]);
}

//#include <stdio.h>
char	**ft_split(char const *s, char c)
{
	char	**letter;
	int	count;
	int	i;
	
	i = 0;
	letter = (char **)malloc(sizeof(char *) * (count_words(s,&c) + 1));
	if(!letter)
	{
		free (letter);
		return (NULL);
	}
	while (i < count_words(s,&c))
	{
		count = 0;
		while (charset_chack(*s, &c))
			s++;
		while (!charset_chack(*s, &c) && *s)
		{	
			count++;
			s++;
		}
		//printf("%c\n",*s)
		letter[i] = likestrdup(s, letter, count, i);
		//printf("%d\n",i);
		i++;
	}
	letter[i] = 0;
	return (letter);
}
