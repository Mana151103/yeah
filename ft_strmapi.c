/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:56:43 by mosada            #+#    #+#             */
/*   Updated: 2023/09/29 18:57:00 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		count;
	int		i;

	i = 0;
	count = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	while (i < count)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
