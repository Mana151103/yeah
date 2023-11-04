/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:54:52 by mosada            #+#    #+#             */
/*   Updated: 2023/08/22 11:23:07 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **s1, char **s2)
{
	char	*pez;

	pez = *s1;
	*s1 = *s2;
	*s2 = pez;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	j = 0;
	n = argc;
	while (argc >= 3)
	{
		while (i < (argc - 1))
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				ft_swap(&argv[i], &argv[i + 1]);
			i++;
		}
		argc--;
		i = 1;
	}
	argc = n;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
