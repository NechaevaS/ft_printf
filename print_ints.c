/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/14 10:36:43 by snechaev         ###   ########.fr       */
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
	if (fmt->conv == 'x' || fmt->conv == 'X' || fmt->conv == 'p')
		base = 16;
	ft_ulltoa_base(str, d, base);
	return (put_result(0, str, fmt));
}

int		print_ll(long long d, t_format *fmt)
{
	char    				str[21];

	ft_memset(str, 0, 21);
	if (d >= 0)
		ft_ulltoa_base(str, (unsigned long long)d, 10);
	else
		ft_ulltoa_base(str, (unsigned long long)(-d), 10);
	return (put_result(d<0, str, fmt));	
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
	char c;
	short s;

	if (fmt->len == hh)
	{
		c = (char)va_arg(*va_l, int);
		d = c;
	}
	else if (fmt->len == h)
	{
		s =(short)va_arg(*va_l, int);
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

int	print_double(long double f, t_format *fmt)
{
	char		str[21];
	char		*str1;
	char		*str2;
	int			pos;
	int			n;
	long double	rem;
	int			len;

	pos = 0;
	n = (int)f;
	rem = f - n;
	while (n >= 1)
	{
		pos++;
		n = n / 10;
	}
	n = (int)f;
	str1 = ft_itoa(n);
	len = 0;
	while(len <= fmt->prec)
	{
		rem = rem * 10;
		len++;
	}
	str2 = ft_itoa(rem);
	if (str2[fmt->prec] >= '5')
		str2[fmt->prec - 1]++;
	ft_memset(str, 0, 21);
	ft_memcpy(str, str1, ft_strlen(str1));
	if (fmt->is_prec && fmt->prec)
	{
		str[pos] = '.';
		pos++;
	}
	ft_memcpy(&str[pos], str2, fmt->prec);
	return (put_result(0, str, fmt));	
}