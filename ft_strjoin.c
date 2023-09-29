/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:42:41 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 12:45:10 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!a)
		return (NULL);
	// b = a;
	ft_strlcpy(a, s1, ft_strlen(s1) + 1);
	// b--;
	ft_strlcpy(a + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	// *b = '\0';
	return (a);
}
