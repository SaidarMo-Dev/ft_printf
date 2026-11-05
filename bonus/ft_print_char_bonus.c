/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:45:54 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/05 21:07:17 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(const t_spec *spec, va_list *ap)
{
	int	count;
	int	check;

	count = 0;
	if (!spec->minus)
	{
		check = put_pad(' ', spec->width - 1);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar_count(va_arg(*ap, int)) == -1)
		return (-1);
	count++;
	if (spec->minus)
	{
		check = put_pad(' ', spec->width - 1);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}
