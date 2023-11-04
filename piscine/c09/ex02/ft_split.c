/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:39:55 by mosada            #+#    #+#             */
/*   Updated: 2023/08/28 23:07:01 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	charset_check(char a, char *charset)
{
	while (*charset)
	{
		if (a == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_word(char	*str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (charset_check(*str, charset))
			flag = 1;
		if (!charset_check(*str, charset) && flag == 1)
		{
			count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

void	ft_likestrdup(char *str, char **letter, int count, int i)
{
	int	n;

	n = 0;
	letter[i] = (char *)malloc(sizeof(char) * (count + 1));
	if (!letter[i])
		return ;
	str -= count;
	while (count)
	{
		letter[i][n] = *str;
		count--;
		n++;
		str++;
	}
	letter[i][n] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**letter;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = count_word(str, charset);
	letter = (char **)malloc(sizeof(char *) * (j + 1));
	if (!letter)
		return (NULL);
	while (i < j)
	{
		count = 0;
		while (charset_check(*str, charset))
			str++;
		while (!charset_check(*str, charset) && *str != '\0')
		{
			count++;
			str++;
		}
		ft_likestrdup(str, letter, count, i);
		i++;
	}
	letter[i] = 0;
	return (letter);
}
