/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:45:54 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 09:10:51 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(const t_spec *spec, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	return (ft_print_field(spec, &c, 1));
}
