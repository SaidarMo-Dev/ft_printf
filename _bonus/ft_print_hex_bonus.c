/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 09:40:18 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 10:30:55 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	hex_common(const t_spec *spec, va_list *ap,
		const char *table, const char *prefix)
{
	t_num		num;
	t_layout	lay;

	lay.pad = 0;
	lay.prefix_len = 0;
	lay.digits = 0;
	lay.zeros = 0;
	num.value = va_arg(*ap, unsigned int);
	num.base = 16;
	if (num.value == 0 || !spec->hash)
		num.prefix = "";
	else
		num.prefix = prefix;
	num.digits = table;
	compute_layout(spec, &num, &lay);
	return (ft_render_num(spec, &num, &lay));
}

int	ft_print_hex_lower(const t_spec *spec, va_list *ap)
{
	return (hex_common(spec, ap, HEX_LOWER, "0x"));
}

int	ft_print_hex_upper(const t_spec *spec, va_list *ap)
{
	return (hex_common(spec, ap, HEX_UPPER, "0X"));
}
