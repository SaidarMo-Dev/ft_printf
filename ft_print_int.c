/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:23:15 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/29 15:00:01 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *ap)
{
	int		count;
	long	value;
	int		check;

	value = va_arg(*ap, int);
	count = 0;
	if (value < 0)
	{
		if (ft_putchar_count('-') == -1)
			return (-1);
		count++;
		value *= -1;
	}
	check = ft_putunbr_base(value, 10, "0123456789");
	if (check == -1)
		return (-1);
	return (count + check);
}
