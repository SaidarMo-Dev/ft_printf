/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 00:13:23 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/03 23:18:31 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char c, va_list *ap, int *total)
{
	int	check;

	check = ft_dispatch(c, ap);
	if (check == -1)
		return (-1);
	*total += check;
	return (0);
}

int	ft_walk(const char *format, va_list *ap)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (ft_putchar_count(format[i]) == -1)
				return (-1);
			total++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			if (ft_handle_format(format[i + 1], ap, &total) == -1)
				return (-1);
			i++;
		}
		else
			return (-1);
		i++;
	}
	return (total);
}
