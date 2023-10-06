/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:46:01 by mosada            #+#    #+#             */
/*   Updated: 2023/10/06 19:54:38 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset_chack(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
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

static char	*likestrdup(char const *s, char **letter, int count, int i)
{
	letter[i] = (char *)malloc(sizeof(char) * (count + 1));
	if (!letter[i])
	{
		while (i)
		{
			free(letter[i]);
			i--;
		}
		free(letter);
		return (NULL);
	}
	ft_strlcpy(letter[i], s, count + 1);
	return (letter[i]);
}

static int	words_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (!charset_chack(*s, c) && *s)
	{
		count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**letter;
	int		count;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	i = 0;
	n = count_words(s, c);
	letter = (char **)malloc(sizeof(char *) * (n + 1));
	if (!letter)
		return (NULL);
	while (i < n)
	{
		count = 0;
		while (charset_chack(*s, c))
			s++;
		count = words_len(s, c);
		letter[i] = likestrdup(s, letter, count, i);
		s += count;
		i++;
	}
	letter[i] = 0;
	return (letter);
}
