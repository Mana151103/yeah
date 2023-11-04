/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:27:22 by mosada            #+#    #+#             */
/*   Updated: 2023/08/26 17:20:14 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(nbr) (nbr % 2 == 0)
# define TRUE 0
# define FALSE 1
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of argument.\n"
# define SUCCESS 0

typedef int	t_bool;

#endif
