/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:20:41 by mosada            #+#    #+#             */
/*   Updated: 2023/08/16 16:51:00 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	s;
	char			*box;

	s = 0;
	box = dest;
	while (*src && s < n)
	{
		*dest = *src;
		dest++;
		src++;
		s++;
	}
	while (s < n)
	{
		*dest = '\0';
		dest++;
		s++;
	}
	return (box);
}
