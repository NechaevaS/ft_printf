/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:18:04 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/01 16:57:44 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 

int find_len_int(int n)
{
    int len;

    len = 1;
    while(n > 0)
    {
        if(n / 10 > 0)
            len++;
        n = n / 10;
    }
    printf("%d\n", len);
    return (len);
}

void	prepare_int(int *d, t_format *fmt, int *wsps)
{
	int     len;
	
	if (fmt->plus && *d > 0)
		fmt->sign = '+';
	if (*d < 0)
	{	
		fmt->sign = '-';
		*d = *d * -1;
	}
	len = find_len_int(*d);
	if (len > fmt->prec)
		fmt->prec = len;
	if (fmt->prec > fmt->w_fild)
	{
		fmt->w_fild = fmt->prec;
		(*wsps) = fmt->w_fild - len;
	}
	else
	{
		(*wsps) = fmt->prec - len;
	}
}

void print_wsps(int fild, int len, int sign, char c)
{
	int		ws;

	ws = fild - len - sign;
	printf("ws %d\n", ws);
	put_some_n(0, c, ws);
}

void	print_rallign(int d, t_format *fmt, int wsps)
{
	if (!fmt->add_0)
	{
		print_wsps(fmt->w_fild, fmt->prec, 1, ' ');
		put_some_n(0, '0', wsps);
		if (fmt->sign)
			ft_putchar(fmt->sign);
		ft_putnbr(d);
	}
	else
	{
		if (fmt->sign)
			ft_putchar(fmt->sign);
		print_wsps(fmt->w_fild, fmt->prec, 1, '0');
		put_some_n(0, '0', wsps);
		ft_putnbr(d);
	}
}

int		print_int(int d, t_format *fmt)
{
	int		wsps;
	int		ws;

	wsps = 0;

	prepare_int(&d, fmt, &wsps);
	if (fmt->minus)
	{
		if (fmt->sign)
			ft_putchar(fmt->sign);
		put_some_n(0, '0', wsps);
		ft_putnbr(d);
		ws = fmt->w_fild - fmt->prec;
		if (fmt->sign)
			ws--;
		if (fmt->add_0)
			put_some_n(0, '0', ws);
		else
			put_some_n(0, ' ', ws);
	}
	else
		print_rallign(d, fmt, wsps);
	return (fmt->w_fild);
}
