/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:34 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/14 18:33:32 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	puthex(unsigned int n, char format)
{
	if (n >= 16)
	{
		if (print_hex(n / 16, format) == -1)
			return (-1);
		print_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			return (print_char(n + '0'));
		else
		{
			if (format == 'x')
				return (print_char(n - 10 + 'a'));
			if (format == 'X')
				return (print_char(n - 10 + 'A'));
			else
				return (-1);
		}
	}
	return (0);
}

int	print_hex(unsigned int value, int asc)
{
	if (value == 0)
		return (print_char('0'));
	if (puthex(value, asc) == -1)
		return (-1);
	return (check_len(value));
}
