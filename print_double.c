/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:38:17 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 17:06:39 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	pow_10_help(int pow)
{
	int n;

	if (pow == 0)
		return (1);
	if (pow == 1)
		return (10);
	if (pow == 2)
		return (100);
	if (pow == 3)
		return (1000);
	n = pow / 2;
	return (pow_10_help(n) * pow_10_help(pow - n));
}

long double	pow_10(int pow)
{
	if (pow >= 0)
		return (pow_10_help(pow));
	return (1 / pow_10_help(-pow));
}

int			find_pow_10(long double f)
{
	int i;

	i = 0;
	while (pow_10(i + 1) < f)
		i++;
	return (i);
}

void		ld_to_str(char *str, long double f, int prec)
{
	long double	pow;
	int			n;
	int			t;
	int			pos;

	pos = 0;
	n = find_pow_10(f);
	while (n >= -prec)
	{
		pow = pow_10(n);
		t = f / pow;
		if (n == -1)
			str[pos++] = '.';
		str[pos++] = '0' + t;
		f = f - t * pow;
		n--;
	}
}

int			print_double(long double f, t_format *fmt)
{
	char	str[124 * 16];
	int		pos;
	int		car;
	int		t;

	ft_memset(str, 0, 124 * 16);
	ld_to_str(str + 2, ((f < 0) ? -f : f), fmt->prec + 1);
	pos = ft_strlen(str + 2) + 2 - 1;
	car = (str[pos] >= '5') ? 1 : 0;
	str[pos--] = 0;
	while (car && pos >= 2)
	{
		if (str[pos] == '.')
			pos--;
		t = str[pos] - '0' + car;
		car = t / 10;
		str[pos--] = '0' + t % 10;
	}
	if (car)
		str[pos] = car + '0';
	pos = (pos <= 2) ? pos + 1 : 2;
	return (put_result(f < 0, str + pos, fmt));
}
