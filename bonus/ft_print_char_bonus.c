/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:45:54 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/05 16:58:05 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(const t_spec *spec, va_list *ap)
{
	int	width;
	
	width = spec->width;
	if (width > 1 && spec->minus)
	{
		while(width > 1)
		{
			write(1, )
		}
	}
	
}