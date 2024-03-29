/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:56:02 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 15:26:18 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, t_format *fmt)
{
	char *s0;

	s0 = "(null)";
	if (!s)
	{
		if (!fmt->is_prec || fmt->prec >= 6)
			s = s0;
		else
			s = "";
	}

	return (put_result(0, s, fmt));
}

int	print_char(char c, t_format *fmt)
{
	char	str[2];

	ft_memset(str, 0, 2);
	if (fmt->prec)
		fmt->prec = 0;
	str[0] = c;
	return (put_result(0, str, fmt));
}

int	print_ptr(void *p, t_format *fmt)
{
	if (!p)
		return (put_result(0, "(nil)", fmt));
	fmt->add_0 = 0;
	fmt->alt_fmt = 0;
	fmt->plus = 0;
	if (!p && !fmt->prec)
		fmt->prec = 0;
	return (print_ull((unsigned long long)p, fmt));
}
