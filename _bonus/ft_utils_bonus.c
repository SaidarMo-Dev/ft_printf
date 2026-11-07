/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 23:26:17 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 12:18:56 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_strlen_pf(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
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

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count_digits(unsigned long long n, unsigned int base)
{
	int	count;

	count = 1;
	while (n >= base)
	{
		n = n / base;
		count++;
	}
	return (count);
}
