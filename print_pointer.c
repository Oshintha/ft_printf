/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:02:55 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/14 16:58:36 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(size_t n)
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

int	put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		if (put_ptr(n / 16) == -1)
			return (-1);
		put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			return (print_char(n + '0'));
		else
		{
			return (print_char((n % 16) - 10 + 'a'));
		}
	}
	return (0);
}

int	print_pointer(size_t ptr)
{
	int	len;

	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	if (ptr == 0)
		len += print_char('0');
	else
	{
		if (put_ptr(ptr) == -1)
			return (-1);
		len += ptr_len(ptr);
	}
	return (len);
}
