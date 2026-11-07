/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:15:33 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 14:19:37 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	compute_layout(const t_spec *spec, const t_num *num, t_layout *lay)
{
	lay->zeros = 0;
	lay->digits = count_digits(num->value, num->base);
	lay->prefix_len = ft_strlen_pf(num->prefix);
	if (spec->has_prec)
		lay->zeros = max_int(0, spec->prec - lay->digits);
	if (spec->zero && !spec->minus && !spec->has_prec)
	{
		lay->zeros = max_int(0, spec->width
				- lay->prefix_len - lay->digits);
	}
	if (spec->has_prec && spec->prec == 0 && num->value == 0)
		lay->digits = 0;
	lay->pad = max_int(0, spec->width
			- (lay->prefix_len + lay->zeros + lay->digits));
}

int	ft_render_num(const t_spec *spec, const t_num *num, const t_layout *lay)
{
	int	total;

	total = 0;
	if (!spec->minus && add_count(&total, put_pad(' ', lay->pad)) == -1)
		return (-1);
	if (add_count(&total,
			ft_putstr_count(num->prefix, lay->prefix_len)) == -1)
		return (-1);
	if (add_count(&total, put_pad('0', lay->zeros)) == -1)
		return (-1);
	if (lay->digits > 0 && add_count(&total,
			ft_putunbr_base(num->value, num->base, num->digits)) == -1)
		return (-1);
	if (spec->minus && add_count(&total, put_pad(' ', lay->pad)) == -1)
		return (-1);
	return (total);
}
