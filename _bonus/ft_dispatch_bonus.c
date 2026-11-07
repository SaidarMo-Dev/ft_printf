/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:45:09 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 16:31:13 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const t_conv	*initialize_table(void)
{
	static t_conv	g_table[10];

	g_table[0] = (t_conv){'c', ft_print_char};
	g_table[1] = (t_conv){'s', ft_print_str};
	g_table[2] = (t_conv){'p', ft_print_ptr};
	g_table[3] = (t_conv){'d', ft_print_int};
	g_table[4] = (t_conv){'i', ft_print_int};
	g_table[5] = (t_conv){'u', ft_print_uint};
	g_table[6] = (t_conv){'x', ft_print_hex_lower};
	g_table[7] = (t_conv){'X', ft_print_hex_upper};
	g_table[8] = (t_conv){'%', ft_print_percent};
	g_table[9] = (t_conv){0, NULL};
	return (g_table);
}

int	ft_dispatch(const t_spec *spec, va_list *ap)
{
	int				i;
	const t_conv	*table = initialize_table();

	i = 0;
	while (table[i].handler != NULL)
	{
		if (table[i].letter == spec->conv)
			return (table[i].handler(spec, ap));
		i++;
	}
	return (-1);
}
