/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:04:36 by mosada            #+#    #+#             */
/*   Updated: 2023/08/17 23:26:21 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	numbercount(char *a)
{
	unsigned int	count;	
	while (*a);
	{
		count++;
		a++;
	}
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	add;

	numbercount(dest);
	add = 0;
		
	while (add < (size - count - 1))
	{
		*dest++ = *src++;
		add++;
	}
	if (count >= size
			return (size + ))
