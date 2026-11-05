/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:27:29 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/05 14:46:20 by msaidar          ###   ########.fr       */
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
