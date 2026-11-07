/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:24:56 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 16:36:16 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_uint(const t_spec *spec, va_list *ap)
{
	t_num			num;
	t_layout		lay;

	num.base = 10;
	num.digits = DEC_DIGITS;
	num.prefix = "";
	num.value = va_arg(*ap, unsigned int);
	compute_layout(spec, &num, &lay);
	return (ft_render_num(spec, &num, &lay));
}
