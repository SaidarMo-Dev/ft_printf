/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 00:13:23 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/31 09:57:39 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_walk(const char *format, va_list *ap)
{
	int	check;
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
			check = ft_dispatch(format[i + 1], ap);
			if (check == -1)
				return (-1);
			total += check;
			i++;
		}
		else
			return (-1);
		i++;
	}
	return (total);
}
