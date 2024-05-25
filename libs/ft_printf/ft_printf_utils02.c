/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:25:59 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 06:45:01 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_num(long n)
{
	int				len;
	char			*var_int;

	var_int = ft_itoa_pf(n);
	len = ft_putstr_fd(var_int, 1);
	free(var_int);
	return (len);
}

int	print_u_int(unsigned int n, unsigned int base)
{
	int		count;
	char	*decimal_base;

	decimal_base = "0123456789";
	if (n < base)
		return (ft_putchar_fd(decimal_base[n], 1));
	else
	{
		count = print_u_int(n / base, base);
		return (count += print_u_int(n % base, base));
	}
}

int	print_hex(char specifier, unsigned long n, unsigned int base)
{
	char	*symbols_lowercase;
	char	*symbols_uppercase;
	int		count;

	symbols_lowercase = "0123456789abcdef";
	symbols_uppercase = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 0);
		return (print_hex(specifier, -n, base));
	}
	else if (n < base && specifier == 'x')
		return (ft_putchar_fd(symbols_lowercase[n], 1));
	else if (n < base && specifier == 'X')
		return (ft_putchar_fd(symbols_uppercase[n], 1));
	else
	{
		count = print_hex(specifier, n / base, base);
		return (count += print_hex(specifier, n % base, base));
	}
}

int	print_ptr(unsigned long ptr)
{
	int		count;
	char	specifier;

	count = 0;
	specifier = 'x';
	if (ptr == 0)
		count = write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += print_hex(specifier, ptr, 16);
	}
	return (count);
}
