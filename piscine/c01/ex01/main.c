/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:31:45 by mosada            #+#    #+#             */
/*   Updated: 2023/08/15 09:36:37 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	int	nbr = 12;
	int *nbr1 = &nbr;
	int	**nbr2 = &nbr1;
	int	***nbr3 = &nbr2;
	int	****nbr4 = &nbr3;
	int	*****nbr5 = &nbr4;
	int	******nbr6 = &nbr5;
	int	*******nbr7 = &nbr6;
	int	********nbr8 = &nbr7;
	int	*********nbr9 = &nbr8;
	ft_ultimate_ft(nbr9);
	printf("%d\n",nbr);
	return 0;
}
