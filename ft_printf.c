/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:25:43 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/01 14:24:05 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_args(va_list *va_l, t_format *fmt)
{
	int d;
	char c;
	char *s;

	if (fmt->conv != '0')
	{
		switch (fmt->conv)
		{
			case 'd':
			d = va_arg(*va_l, int);
			return(print_int(d, fmt));
		// if (fmt->conv == 'c')
		// 	return (print_char(va_l, fmt));
		// if (fmt->conv == 'o')
		// 	return (print_okt(va_l, fmt));
		// if (fmt->conv == 'u')
		// 	return (print_dec(va_l, fmt));
		// if (fmt->conv == 'x' || fmt->conv == 'X')
		// 	return (print_hex(va_l, fmt));
		// if (fmt->conv == 'p')
		// 	return (print_ptr(va_l, fmt));
		case 's':
			s = va_arg(*va_l, char *);
			return(print_str(s, fmt));
		case 'c':
			c = (char)va_arg(*va_l, int);
			return(print_char(c, fmt));
		case '%':
			return(print_char('%', fmt));
		case 'p':
			d = va_arg(*va_l, int);
			return(print_int(d, fmt));
		}
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		va_l;
	int			len;
	int			all_len;
	t_format	*fmt;


	all_len = 0;
	fmt = init();
	va_start(va_l, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			all_len++;
		}
		else
		{
			len = arg_parse(&format, fmt);

			len = print_args(&va_l, fmt);
			(format)++;
			all_len = all_len + len;
		}
	}
	va_end(va_l);
	return (all_len);
}
