/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:22:29 by mosada            #+#    #+#             */
/*   Updated: 2023/10/15 16:18:28 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>

size_t	ft_putnbr(int n);
size_t	ft_putunbr(unsigned int n);
size_t	putaddress(void *a);
size_t	change_to_hexadecimal(unsigned int v, bool is_lower);
size_t	ft_putstr(char *s);
int		ft_printf(const char *fmt, ...);
size_t	is_x(va_list ap, char c);
size_t	is_uint(va_list ap);

#endif