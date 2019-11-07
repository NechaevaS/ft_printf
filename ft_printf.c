/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:25:43 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/06 15:14:05 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	print_args(va_list *va_l, t_format *fmt)
{
	char	c;
	char	*s;
	// double	f;
	void	*p;
//	int		d;

	if (fmt->conv != '0')
	{
		if (fmt->conv == 'd' || fmt->conv == 'i')
			return (print_int(va_l, fmt));
		if (fmt->conv == 'u' || fmt->conv == 'o' || fmt->conv == 'x'
			|| fmt->conv == 'X')
			return (print_uox(va_l, fmt));
		if (fmt->conv == 'c')
		{
			c = va_arg(*va_l, int);
			return (print_char(c, fmt));
		}
		if (fmt->conv == 's')
		{
			s = va_arg(*va_l, char *);
			return (print_str(s, fmt));
		}
		if (fmt->conv == '%')
			return (print_char('%', fmt));
		// if (fmt->conv == 'f')
		// {
		// 	f = va_arg(*va_l, double);
		// 	return (print_double(f, fmt));
		// }
		if (fmt->conv == 'p')
		{
			p = va_arg(*va_l, void *);
			return (print_ptr(p, fmt));
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
			arg_parse(&format, fmt);
			len = print_args(&va_l, fmt);
			(format)++;
			all_len = all_len + len;
		}
	}
	va_end(va_l);
	return (all_len);
}
