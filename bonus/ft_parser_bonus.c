/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:46:42 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/06 18:12:26 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_spec(t_spec *spec)
{
	spec->has_prec = 0;
	spec->prec = 0;
	spec->minus = 0;
	spec->width = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->conv = 0;
	spec->zero = 0;
	spec->hash = 0;
}

int	parse_flags(const char *s, t_spec *spec)
{
	int	count;

	count = 0;
	while (is_inflags(*s))
	{
		set_flag(spec, *s);
		count++;
		s++;	
	}
	return (count);
}

int	parse_width(const char *s, t_spec *spec)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		count ++;
		s++;
	}
	spec->width = res;
	return (count);
}

int	parse_prec(const char *s, t_spec *spec)
{
	int	count;
	int	res;

	res = 0;
	if (*s != '.')
		return (0);
	count = 1;
	s++;
	spec->has_prec = 1;
	while (*s >= '0' && *s <= '9')
	{
		count ++;
		res = res * 10 + *s - '0';
		s++;
	}
	spec->prec = res;
	return (count);
}

int	parse_spec(const char *s, t_spec *spec)
{
	int	count;

	count = 1;
	init_spec(spec);
	count += parse_flags(s + count, spec);
	count += parse_width(s + count, spec);
	count += parse_prec(s + count, spec);
	s = s + count;
	if (!*s)
		return (-1);
	spec->conv = *s;
	return (count + 1);
}
