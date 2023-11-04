/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:05:55 by mosada            #+#    #+#             */
/*   Updated: 2023/08/31 15:14:09 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		ft_atoi(char *str);
int		operator(int s1, int s2, char s3);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

void	division(int s1, int s2, char op, int (*f)(int, int, char))
{
	if (s2 == 0)
	{
		if (op == '/')
			ft_putstr("Stop : division by zero");
		else if (op == '%')
			ft_putstr("Stop : modulo by zero");
	}
	else
		ft_putnbr(f(s1, s2, op));
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	int	ans;
	int	(*f)(int, int, char);

	ans = 0;
	if (argc != 4)
		return (0);
	f = operator;
	if (ft_strlen(argv[2]) != 1)
		write (1, "0", 1);
	else if (*argv[2] == '+')
		ft_putnbr(f(ft_atoi(argv[1]), ft_atoi(argv[3]), '+'));
	else if (*argv[2] == '-')
		ft_putnbr(f(ft_atoi(argv[1]), ft_atoi(argv[3]), '-'));
	else if (*argv[2] == '*')
		ft_putnbr(f(ft_atoi(argv[1]), ft_atoi(argv[3]), '*'));
	else if (*argv[2] == '/')
		division(ft_atoi(argv[1]), ft_atoi(argv[3]), '/', f);
	else if (*argv[2] == '%')
		division(ft_atoi(argv[1]), ft_atoi(argv[3]), '%', f);
	else
		write (1, "0", 1);
	write (1, "\n", 1);
	return (0);
}
