/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:35 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 06:47:24 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format_str, ...);
int		print_format_str(char specifier, va_list ap);
int		print_num(long n);
int		print_u_int(unsigned int n, unsigned int base);
int		print_hex(char specifier, unsigned long n, unsigned int base);
int		print_ptr(unsigned long ptr);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_count_digits_pf(int n);
char	*ft_makestr_pf(int n, int digits, char *str);
char	*ft_itoa_pf(int n);

#endif
