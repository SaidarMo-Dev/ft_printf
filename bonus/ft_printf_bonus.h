/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidar <msaidar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 23:26:17 by msaidar           #+#    #+#             */
/*   Updated: 2026/11/07 08:59:19 by msaidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define DEC_DIGITS "0123456789"

typedef struct s_spec
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		has_prec;
	int		prec;
	char	conv;
}	t_spec;

typedef struct s_num
{
	unsigned long long	value;
	unsigned int		base;
	const char			*digits;
	const char			*prefix;
}	t_num;

typedef struct s_layout
{
	int	digits;
	int	zeros;
	int	pad;
	int	prefix_len;
}	t_layout;

typedef int	(*t_handler)(const t_spec *spec, va_list *ap);

typedef struct s_conv
{
	char		letter;
	t_handler	handler;
}	t_conv;

int		ft_printf(const char *format, ...);
int		ft_walk(const char *format, va_list *ap);

int		parse_flags(const char *s, t_spec *spec);
int		parse_width(const char *s, t_spec *spec);
int		parse_prec(const char *s, t_spec *spec);
int		parse_spec(const char *s, t_spec *spec);

int		ft_dispatch(const t_spec *spec, va_list *ap);

int		ft_print_char(const t_spec *spec, va_list *ap);
int		ft_print_str(const t_spec *spec, va_list *ap);
int		ft_print_percent(const t_spec *spec, va_list *ap);

int		ft_print_int(const t_spec *spec, va_list *ap);
int		ft_print_uint(const t_spec *spec, va_list *ap);
int		ft_print_hex_lower(const t_spec *spec, va_list *ap);
int		ft_print_hex_upper(const t_spec *spec, va_list *ap);

int		ft_print_ptr(const t_spec *spec, va_list *ap);

int		ft_print_num(const t_spec *spec, const t_num *num);
int		ft_print_field(const t_spec *spec, const char *s, int len);

int		ft_putchar_count(char c);
int		ft_putstr_count(const char *s, size_t len);
size_t	ft_strlen_pf(const char *s);
int		put_pad(char c, int n);
int		max_int(int a, int b);
int		is_inflags(char c);
void	set_flag(t_spec *spec, char flag);
int		print_width(int widht);
int		add_count(int *total, int res);

int		ft_putunbr_base(unsigned long long n, unsigned int base,
			const char *digits);
int		count_digits(unsigned long long n, unsigned int base);

void	compute_layout(const t_spec *spec, const t_num *num, t_layout *lay);
int		ft_render_num(const t_spec *spec, const t_num *num,
			const t_layout *lay);
#endif