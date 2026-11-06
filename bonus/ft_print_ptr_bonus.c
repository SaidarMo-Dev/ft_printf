/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:28:12 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 19:26:54 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static	int	ft_render_ptr(const t_spec *spec, t_layout *lay, const t_num *num)
{
	int	total;

	total = 0;
	if (!spec->minus && add_count(&total, put_pad(' ', lay->pad)) == -1)
		return (-1);
	if (spec->plus)
	{
		if (add_count(&total, ft_putstr_count("+", 1)) == -1)
			return (-1);
		if (spec->has_prec)
			lay->zeros--;
	}
	if (add_count(&total, ft_putstr_count("0x", 2)) == -1)
		return (-1);
	if (add_count(&total, put_pad('0', lay->zeros)) == -1)
		return (-1);
	if (add_count(&total, ft_putunbr_base(num->value, num->base,
				num->digits)) == -1)
		return (-1);
	if (spec->minus && add_count(&total, put_pad(' ', lay->pad)) == -1)
		return (-1);
	return (total);
}

static const char	*ptr_prefix(const t_spec *spec)
{
	if (spec->plus)
		return ("+0x");
	if (spec->space)
		return (" 0x");
	return ("0x");
}
 
int	ft_print_ptr(const t_spec *spec, va_list *ap)
{
	int			count;
	t_layout	lay;
	t_num		num;

	lay.pad = 0;
	lay.zeros = 0;
	num.base = 16;
	num.value = (unsigned long long) va_arg(*ap, void *);
	num.prefix = ptr_prefix(spec);
	num.digits = "0123456789abcdef";
	count = 0;
	if (num.value == 0)
		return (ft_print_field(spec, "(nil)", 5));
	compute_layout(spec, &num, &lay);
	return (ft_render_num(spec, &lay, &num));
}
