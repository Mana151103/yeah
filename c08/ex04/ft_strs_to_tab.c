/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:36:05 by mosada            #+#    #+#             */
/*   Updated: 2023/08/26 11:36:15 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_strlcpy(char *s1, char *s2)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		s1[j] = s2[j];
		j++;
	}
	s1[j] = '\0';
}

int	ft_count(char *src)
{
	int	count;

	count = 0;
	while (*src)
	{
		src++;
		count++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*letter;

	letter = (char *)malloc(sizeof(char) * (ft_count(src) + 1));
	if (*letter)
		return (NULL);
	ft_strlcpy(letter, src);
	return (letter);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	i = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (NULL);
	while (i < ac)
	{
		result[i].str = av[i];
		result[i].size = ft_count(av[i]);
		result[i].copy = ft_strdup(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
