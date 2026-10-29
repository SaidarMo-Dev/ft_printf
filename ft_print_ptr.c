/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:07:56 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/29 23:09:39 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list *ap)
{
	void	*value;
	int		count;
	int		check;

	value = va_arg(*ap, void *);
	if (value == NULL)
		return (ft_putstr_count("(nil)", 5));
	count = ft_putstr_count("0x", 2);
	if (count == -1)
		return (-1);
	check = ft_putunbr_base((uintptr_t)value, 16, "0123456789abcdef");
	if (check == -1)
		return (-1);
	return (count + check);
}
