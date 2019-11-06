/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 18:13:30 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ull(unsigned long long d, t_format *fmt)
{
	char    				str[21];
	unsigned				base;

	base = 10;
	ft_memset(str, 0, 21);
	if (fmt->conv == 'o')
		base = 8;
	if (fmt->conv == 'x' || fmt->conv == 'X')
		base = 16;
	ft_ulltoa_base(str, d, base);
	return (put_str_fmt(0, str, fmt));
}

int		print_ll(long long d, t_format *fmt)
{
	char    				str[21];

	ft_memset(str, 0, 21);
	if (d >= 0)
		ft_ulltoa_base(str, (unsigned long long)d, 10);
	else
		ft_ulltoa_base(str, (unsigned long long)(-d), 10);
	return (put_str_fmt(d<0, str, fmt));	
}

int	print_uox(va_list *va_l, t_format *fmt)
{
	unsigned long long int d;

	if (fmt->len == hh)
		d = va_arg(*va_l, unsigned int);
	else if (fmt->len == h)
		d = va_arg(*va_l, unsigned int);
	else if (fmt->len == l)
		d = va_arg(*va_l, unsigned long);
	else if (fmt->len == ll)
		d = va_arg(*va_l, unsigned long long);
	else
		d = va_arg(*va_l, unsigned int);
	return (print_ull(d, fmt));
}

int	print_int(va_list *va_l, t_format *fmt)
{
	long long int d;

	if (fmt->len == hh)
		d = va_arg(*va_l, int);
	else if (fmt->len == h)
		d = va_arg(*va_l, int);
	else if (fmt->len == l)
		d = va_arg(*va_l, long);
	else if (fmt->len == ll)
		d = va_arg(*va_l, long long);
	else
		d = va_arg(*va_l, int);
	return (print_ll(d, fmt));
}