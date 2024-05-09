/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshinth <aoshinth@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:02:55 by aoshinth          #+#    #+#             */
/*   Updated: 2024/05/09 17:39:24 by aoshinth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_string(unsigned long value, int *strlen)
{
	int				i;
	unsigned long	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	*strlen = i - 1;
	return (str);
}

int	print_pointer(unsigned long value, int asc)
{
	unsigned long	temp;
	char			*printout;
	int				i;
	int				*ptr;

	ptr = &i;
	temp = value;
	printout = create_string(value, ptr);
	if (!printout)
		return (0);
	while (temp != 0 && i-- >= 0)
	{
		if ((temp % 16) < 10)
			printout[i + 1] = (temp % 16) + 48;
		else
			printout[i + 1] = (temp % 16) + asc;
		temp = temp / 16;
	}
	i = ft_strlen(printout);
	i = i + print_string("0x");
	ft_putstr_fd(printout, 1);
	free(printout);
	if (value == 0)
		i += print_char('0');
	return (i);
}
