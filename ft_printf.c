/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:25:43 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 18:02:21 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlong_depend(va_list *va_l, t_format *fmt)
{
	long long int d;

	// switch (fmt->len)
	// {
// 		case h:
// 			d = (short)va_arg(*va_l, long long int);
// 			return(print_short_int(d, fmt));
// 		case hh:
// 			d = (signed char)va_arg(*va_l, long long int);
// 			return(print_sign_char(d, fmt));
// 		case l:
// 			d = (long)va_arg(*va_l, long long int);
// 			return(print_long(d, fmt));
// 		case ll:
// 			d = (long long)va_arg(*va_l, long long int);
// 			return(print_long_long(d, fmt));
// 		default:
			d = (int)va_arg(*va_l, int);
			return(print_int(d, fmt));

}

int	print_args(va_list *va_l, t_format *fmt)
{
//	int		d;
	char	c;
	char	*s;
	// double	f;
	// void	*p;

	if (fmt->conv != '0')
	{
		if (fmt->conv == 'd' || fmt->conv == 'd')
			return (intlong_depend(va_l, fmt));
		// if (fmt->conv == 'u' || fmt->conv == 'o' || fmt->conv == 'x' || fmt->conv == 'X')
		// 	return (uintlong_depend(va_l, fmt));
		if (fmt->conv == 'c')
		{
			c = (char)va_arg(*va_l, int);
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
		// if (fmt->conv == 'p')
		// {
		// 	p = va_arg(*va_l, void *);
		// 	return (print_ptr(p, fmt));
		// }
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
