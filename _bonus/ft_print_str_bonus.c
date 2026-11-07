/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:12:13 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 09:10:20 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	body_len(const t_spec *spec, const char *s)
{
	int	len;

	if (!s)
	{
		len = 6;
		if (spec->has_prec && spec->prec < len)
			len = 0;
		return (len);
	}
	len = (int)ft_strlen_pf(s);
	if (spec->has_prec && spec->prec < len)
		len = spec->prec;
	return (len);
}

int	ft_print_str(const t_spec *spec, va_list *ap)
{
	const char	*s;
	int			len;

	s = va_arg(*ap, char *);
	len = body_len(spec, s);
	if (!s)
		s = "(null)";
	return (ft_print_field(spec, s, len));
}
