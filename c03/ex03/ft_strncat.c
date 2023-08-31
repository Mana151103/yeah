/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:34:03 by mosada            #+#    #+#             */
/*   Updated: 2023/08/18 10:45:09 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*box;
	unsigned int	count;

	count = 0;
	box = dest;
	while (*dest)
		dest++;
	while (*src != '\0' && count < nb)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return (box);
}
