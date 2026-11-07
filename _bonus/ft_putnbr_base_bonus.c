/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 23:26:17 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/30 09:50:40 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	convert_to_base(unsigned long long int number, unsigned int base,
		const char *digits)
{
	int	left;

	left = 0;
	if (number >= base)
		left = convert_to_base(number / base, base, digits);
	if (left == -1)
		return (-1);
	if (ft_putchar_count(digits[number % base]) == -1)
		return (-1);
	return (left + 1);
}

int	ft_putunbr_base(unsigned long long n, unsigned int base,
		const char *digits)
{
	if (base < 2)
		return (-1);
	return (convert_to_base(n, base, digits));
}
