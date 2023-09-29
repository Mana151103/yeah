/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:42:41 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 14:54:10 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		count1;
	int		count2;

	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (count1 + count2 + 1));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, count1 + 1);
	ft_strlcpy(a + count1, s2, count2 + 1);
	return (a);
}
