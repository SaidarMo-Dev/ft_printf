/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:40:57 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 14:31:41 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_int(const t_spec *spec, va_list *ap)
{
	t_num			num;
	long			value;
	t_layout		lay;

	value = va_arg(*ap, int);
	num.base = 10;
	num.digits = DEC_DIGITS;
	if (value < 0)
	{
		num.prefix = "-";
		value *= -1;
	}
	else if (spec->plus)
		num.prefix = "+";
	else if (spec->space)
		num.prefix = " ";
	else
		num.prefix = "";
	num.value = value;
	compute_layout(spec, &num, &lay);
	return (ft_render_num(spec, &num, &lay));
}
