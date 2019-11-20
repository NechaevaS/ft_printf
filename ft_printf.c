/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:25:43 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 17:06:39 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_fmt(t_format *fmt)
{
	if (fmt->conv == 'i')
		fmt->conv = 'd';
	if (fmt->conv == 'f' && !fmt->is_prec)
	{
		fmt->is_prec = 1;
		fmt->prec = 6;
	}
	if ((fmt->add_0 && fmt->minus) || (fmt->prec > 0 && fmt->conv != 'f')
		|| fmt->conv == 's')
		fmt->add_0 = 0;
	if ((fmt->conv != 'd' && fmt->conv != 'f') && fmt->plus)
		fmt->plus = 0;
	if ((fmt->conv != 'f' && fmt->conv != 'x' && fmt->conv != 'X'
		&& fmt->conv != 'o') && fmt->alt_fmt)
		fmt->alt_fmt = 0;
	if (fmt->sps && fmt->plus)
		fmt->sps = 0;
}

int		print_args(va_list *va_l, t_format *fmt)
{
	if (fmt->conv != '0')
	{
		if (fmt->conv == 'd' || fmt->conv == 'i')
			return (print_int(va_l, fmt));
		if (fmt->conv == 'u' || fmt->conv == 'o' || fmt->conv == 'x'
			|| fmt->conv == 'X')
			return (print_uox(va_l, fmt));
		if (fmt->conv == 'c')
			return (print_char((char)va_arg(*va_l, int), fmt));
		if (fmt->conv == 's')
			return (print_str((char *)va_arg(*va_l, char *), fmt));
		if (fmt->conv == '%')
			return (write(1, "%", 1));
		if (fmt->conv == 'f')
		{
			if (fmt->len == L)
				return (print_double(va_arg(*va_l, long double), fmt));
			else
				return (print_double((long double)va_arg(*va_l, double), fmt));
		}
		if (fmt->conv == 'p')
			return (print_ptr((void *)va_arg(*va_l, void *), fmt));
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		va_l;
	int			len;
	t_format	fmt;

	len = 0;
	va_start(va_l, format);
	while (*format)
	{
		init_fmt(&fmt);
		if (*format != '%')
		{
			ft_putchar(*format);
			len++;
			format++;
		}
		else
		{
			arg_parse(&format, &fmt);
			len = len + print_args(&va_l, &fmt);
			if (*format)
				(format)++;
		}
	}
	va_end(va_l);
	return (len);
}
