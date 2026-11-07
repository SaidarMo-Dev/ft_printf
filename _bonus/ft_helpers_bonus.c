/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:27:29 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 17:55:44 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_inflags(char c)
{
	const char	*flags;

	flags = "-+0# ";
	while (*flags)
	{
		if (c == *flags)
			return (1);
		flags++;
	}
	return (0);
}

void	set_flag(t_spec *spec, char flag)
{
	if (flag == '0')
		spec->zero = 1;
	else if (flag == '-')
		spec->minus = 1;
	else if (flag == '+')
		spec->plus = 1;
	else if (flag == '#')
		spec->hash = 1;
	else if (flag == 32)
		spec->space = 1;
}

int	put_pad(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		if (ft_putchar_count(c) == -1)
			return (-1);
		count++;
		n--;
	}
	return (count);
}

int	add_count(int *total, int res)
{
	if (res == -1)
		return (-1);
	*total += res;
	return (0);
}

int	ft_print_field(const t_spec *spec, const char *s, int len)
{
	int	pad;
	int	total;

	total = 0;
	pad = spec->width - len;
	if (!spec->minus && add_count(&total, put_pad(' ', pad)) == -1)
		return (-1);
	if (add_count(&total, ft_putstr_count(s, len)) == -1)
		return (-1);
	if (spec->minus && add_count(&total, put_pad(' ', pad)) == -1)
		return (-1);
	return (total);
}
