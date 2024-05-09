/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:25:18 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/09 18:10:45 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *input, void *arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char((int)arg);
	else if (*input == 's')
		i += print_string((char *)arg);
	else if (*input == 'p')
		i += print_pointer((unsigned long)arg, 87);
	else if (*input == 'd')
		i += print_int((int)arg);
	else if (*input == 'i')
		i += print_int((int)arg);
	else if (*input == 'u')
		i += print_unsigned((unsigned int)arg);
	else if (*input == 'x')
		i += print_hex((unsigned int)arg, 87);
	else if (*input == 'X')
		i += print_hex((unsigned int)arg, 55);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, va_arg(args, void *));
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i += print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
