/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:15:05 by mosada            #+#    #+#             */
/*   Updated: 2023/08/23 20:13:01 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *s1, char *s2)
{
	char	*box;

	box = s1;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (box);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_strlen_sum(char **strs, int size, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
		count += ft_strlen(strs[i++]);
	return (count + ft_strlen(sep) * (size - 1));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*letter;
	char	*address;

	i = 0;
	count = 0;
	if (size == 0)
	{
		letter = (char *)malloc(1);
		return (letter);
	}
	count = ft_strlen_sum(strs, size, sep);
	letter = (char *)malloc(sizeof(char) * (count + 1));
	*letter = '\0';
	address = letter;
	while (i < size)
	{
		ft_strcat(letter, strs[i]);
		if (i != size - 1)
			ft_strcat(letter, sep);
		i++;
	}
	return (address);
}
