/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:25:43 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/07 14:36:42 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_fmt(t_format *fmt)
{
	if (fmt->conv != 'f' && fmt->prec == -1)
		fmt->prec = 0;
	if ((fmt->add_0 && fmt->minus) || fmt->prec > 0)
		fmt->add_0 = 0;
	if (fmt->prec > fmt->w_fild)
		fmt->w_fild = fmt->prec;
	if (fmt->conv == 'c' || fmt->conv == 's' || fmt->conv == 'p')
	{
		if (fmt->conv != 's')
			fmt->prec = 0;
		fmt->plus = 0;
		fmt->add_0 = 0;
	}
	// if (fmt->len == L && fmt->conv != 'f')
	// 	fmt->len == '\0';
	if ((fmt->conv != 'd' || fmt->conv != 'f') && fmt->plus)
		fmt->plus = 0;
	if (fmt->conv == 'f' && fmt->prec == -1)
		fmt->prec = 6;
	if ((fmt->conv != 'f' && fmt->conv != 'x' && fmt->conv != 'X'
		&& fmt->conv != 'o') && fmt->alt_fmt)
		fmt->alt_fmt = 0;
}

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
	t_format	fmt;


	all_len = 0;
	init_fmt(&fmt);
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
			arg_parse(&format, &fmt);
			modify_fmt(&fmt);
			len = print_args(&va_l, &fmt);
			(format)++;
			all_len = all_len + len;
		}
	}
	va_end(va_l);
	return (all_len);
}
