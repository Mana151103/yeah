/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:33:20 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 15:39:25 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
void	ft_change_number(long nb, int count, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_atoi_base(nbr, base_from) || !ft_atoi_base(nbr, base_to))
		return (NULL);
	ft_change_number(ft_atoi_base(nbr, base_from), 10, "0123456789");
	
}