/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:30:05 by msaidar           #+#    #+#             */
/*   Updated: 2026/10/29 23:21:55 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

typedef int	(*t_handler)(va_list *ap);

typedef struct s_conv
{
	char		letter;
	t_handler	handler;
}	t_conv;

int		ft_printf(const char *format, ...);
int		ft_walk(const char *format, va_list *ap);

int		ft_dispatch(char conv, va_list *ap);

int		ft_print_char(va_list *ap);
int		ft_print_str(va_list *ap);
int		ft_print_percent(va_list *ap);

int		ft_print_int(va_list *ap);
int		ft_print_uint(va_list *ap);

int		ft_print_hex_lower(va_list *ap);
int		ft_print_hex_upper(va_list *ap);
int		ft_print_ptr(va_list *ap);

int		ft_putchar_count(char c);
int		ft_putstr_count(const char *s, size_t len);
size_t	ft_strlen_pf(const char *s);
int		ft_putunbr_base(unsigned long long n, unsigned int base,
			const char *digits);

#endif
