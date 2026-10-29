/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:58:37 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/29 14:22:15 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *ap)
{
	int		len;
	char	*s;

	s = va_arg(*ap, char *);
	len = ft_strlen_pf(s);
	return (ft_putstr_count(s, len));
}
