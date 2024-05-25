/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:31:57 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 06:46:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		i = write(1, "(null)", 6);
	else
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	return (i);
}

int	ft_count_digits_pf(int n)
{
	int	digits;

	digits = 0;
	if (n == -2147483648)
	{
		n = (n / 10) * -1;
		digits += 2;
	}
	if (n < 0)
	{
		n *= -1;
		digits++;
	}
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	digits++;
	return (digits);
}

char	*ft_makestr_pf(int n, int digits, char *str)
{
	int		begin;
	long	max;

	begin = 0;
	max = n;
	str[digits] = '\0';
	if (max < 0)
	{
		str[0] = '-';
		begin = 1;
		max *= -1;
	}
	while (digits > begin)
	{
		str[digits - 1] = (max % 10) + '0';
		max /= 10;
		digits--;
	}
	return (str);
}

char	*ft_itoa_pf(int n)
{
	char	*str;
	int		size;

	size = ft_count_digits_pf(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	return (ft_makestr_pf(n, size, str));
}
