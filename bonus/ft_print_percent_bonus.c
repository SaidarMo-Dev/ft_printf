/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 09:12:46 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 09:30:42 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_percent(const t_spec *spec, va_list *ap)
{
	(void)ap;
	return (ft_print_field(spec, "%", 1));
}