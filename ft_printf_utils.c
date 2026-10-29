/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:02:27 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/29 23:06:09 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pf(const char *s)
{
	int	len;

	len = 0;
	while (*s)
		len++;
	return (len);
}

int	ft_putchar_count(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_count(const char *s, size_t len)
{
	int	count;

	count = write(1, s, len);
	if (count == -1)
		return (-1);
	return (count);
}

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
