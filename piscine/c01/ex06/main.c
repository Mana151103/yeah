/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:56:28 by mosada            #+#    #+#             */
/*   Updated: 2023/08/14 16:56:59 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(void)
{
	char	*str;
	int	count;

	str = "hello";
	count = ft_strlen(str);
	printf("%d\n",count);
	return 0;
}
