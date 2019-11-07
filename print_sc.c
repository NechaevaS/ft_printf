/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:56:02 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/06 15:43:22 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(char *s, t_format *fmt)
{
	return (put_result(0, s, fmt));
}

int print_char(char c, t_format *fmt)
{
	char	str[2];
	if (fmt->prec)
		fmt->prec = 0;
	str[0] = c;
	str[1] = '\0';
	return (put_result(0, str, fmt));
}

int	print_ptr(void *p, t_format *fmt)
{
	fmt->add_0 = 0;
	fmt->alt_fmt = 0;
    fmt->plus = 0;
	fmt->prec = 14;
	return (print_ull((unsigned long long)p, fmt));
}
