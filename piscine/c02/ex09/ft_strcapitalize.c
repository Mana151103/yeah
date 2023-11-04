/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:16:46 by mosada            #+#    #+#             */
/*   Updated: 2023/08/16 14:25:22 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*box;
	int		start;

	box = str;
	start = 1;
	while (*str)
	{
		if (('a' <= *str && *str <= 'z')
			|| ('A' <= *str && *str <= 'Z') || ('0' <= *str && *str <= '9'))
		{
			if (start)
			{
				if ('a' <= *str && *str <= 'z')
					*str -= 32;
				start = 0;
			}
			else if ('A' <= *str && *str <= 'Z')
				*str += 32;
		}
		else
			start = 1;
		str++;
	}
	return (box);
}
