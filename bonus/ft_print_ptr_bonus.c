/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:28:12 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 11:55:35 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_ptr(const t_spec *spec, va_list *ap)
{
	void	*value;
	int		hexdigits;
	int		count;
	int		zeros;
	
	count = 0;
	zeros = 0;
	value = va_arg(*ap, void *);
	if (value == NULL)
		return (ft_print_field(spec, "(nil)", 5));
	hexdigits = count_hexdigits(value);
	if (spec->has_prec)
		zeros = max_int(0, hexdigits - spec->prec);	
	
}