/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:28:26 by mosada            #+#    #+#             */
/*   Updated: 2023/10/12 10:48:16 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(int n, int fd);
void	putaddress_fd(void *a, int fd);
void	change_to_hexadecimal_up(int v);
void	change_to_hexadecimal_low(int v);
void	ft_putstr_fd(char *s, int fd);

#endif