/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:01:41 by mosada            #+#    #+#             */
/*   Updated: 2023/11/29 12:06:54 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	flag;
	int	count;

	flag = 1;
	count = 0;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		if (flag == 1 && (*s != c))
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
		return (NULL);
	}
	ft_strlcpy(letter[i], s, count + 1);
	return (letter[i]);
}

static int	words_len(char const *s, char c)
{
	int	count;

	count = 0;
	while ((*s != c) && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static char	**address_change(const char *s, char c, char **letter, int n)
{
	int	count;
	int	i;

	i = 0;
	while (i < n)
	{
		count = 0;
		while (*s == c)
			s++;
		count = words_len(s, c);
		letter[i] = likestrdup(s, letter, count, i);
		if (!letter[i])
		{
			free(letter);
			return (NULL);
		}
		s += count;
		i++;
	}
	letter[i] = 0;
	return (letter);
}

char	**ft_split(char const *s, char c)
{
	char	**letter;
	char	**p;
	int		n;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	letter = (char **)malloc(sizeof(char *) * (n + 1));
	if (!letter)
		return (NULL);
	p = address_change(s, c, letter, n);
	return (p);
}
