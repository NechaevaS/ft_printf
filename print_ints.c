/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 15:23:28 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ull(unsigned long long d, t_format *fmt)
{
	char		str[24];
	unsigned	base;

	base = 10;
	ft_memset(str, 0, 24);
	if (fmt->conv == 'o')
		base = 8;
	if (fmt->conv == 'x' || fmt->conv == 'X' || fmt->conv == 'p')
		base = 16;
	ft_ulltoa_base(str, d, base);
	return (put_result(0, str, fmt));
}

int		print_ll(long long d, t_format *fmt)
{
	char	str[21];

	ft_memset(str, 0, 21);
	if (d >= 0)
		ft_ulltoa_base(str, (unsigned long long)d, 10);
	else
		ft_ulltoa_base(str, (unsigned long long)(-d), 10);
	return (put_result(d < 0, str, fmt));
}

int		print_uox(va_list *va_l, t_format *fmt)
{
	unsigned long long int	d;
	unsigned char			c;
	unsigned short			s;

	if (fmt->len == hh)
	{
		c = (unsigned char)va_arg(*va_l, unsigned int);
		d = c;
	}
	else if (fmt->len == h)
	{
		s = (unsigned short)va_arg(*va_l, unsigned int);
		d = s;
	}
	else if (fmt->len == l)
		d = va_arg(*va_l, unsigned long);
	else if (fmt->len == ll)
		d = va_arg(*va_l, unsigned long long);
	else
		d = va_arg(*va_l, unsigned int);
	return (print_ull(d, fmt));
}

int		print_int(va_list *va_l, t_format *fmt)
{
	long long int	d;
	char			c;
	short			s;

	if (fmt->len == hh)
	{
		c = (char)va_arg(*va_l, int);
		d = c;
	}
	else if (fmt->len == h)
	{
		s = (short)va_arg(*va_l, int);
		d = s;
	}
	else if (fmt->len == l)
		d = va_arg(*va_l, long);
	else if (fmt->len == ll)
		d = va_arg(*va_l, long long);
	else
		d = va_arg(*va_l, int);
	return (print_ll(d, fmt));
}
