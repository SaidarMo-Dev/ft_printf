/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:46:42 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/04 20:13:36 by msaidar          ###   ########.fr       */
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
}
int	parse_width(const char *s, t_spec *spec);
int	parse_prec(const char *s, t_spec *spec);

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