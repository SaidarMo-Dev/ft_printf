/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walk_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 00:13:23 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 18:27:48 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_handle_format(const char *format, va_list *ap,
				int *total, int *read)
{
	t_spec	spec;

	if (add_count(read, parse_spec(format, &spec)) == -1)
		return (-1);
	if (add_count(total, ft_dispatch(&spec, ap)))
		return (-1);
	return (0);
}

int	ft_walk(const char *format, va_list *ap)
{
	int	total;
	int	i;
	int	read;

	total = 0;
	while (*format)
	{
		read = 0;
		if (*format != '%')
		{
			if (ft_putchar_count(*format) == -1)
				return (-1);
			total++;
			format++;
		}
		else if (*format == '%' && *format)
		{
			if (ft_handle_format(format, ap, &total, &read) == -1)
				return (-1);
			format += read;
		}
		else
			return (-1);
	}
	return (total);
}
