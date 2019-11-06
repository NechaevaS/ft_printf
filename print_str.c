/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:56:02 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/01 16:23:48 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void put_some_n(char *str, char c, int n)
{
	int i = 0;

	if (n < 0)
		return ;
	if (c)
	{
		while(i < n)
		{
			write (1, &c, 1);
			i++;
		}
	}
	else
	{
		while(i < n)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int print_str(char *s, t_format *fmt)
{
	int     len;
	int		wsps;

	len = ft_strlen(s);
	if (len > fmt->w_fild)
		fmt->w_fild = len;
	if (!fmt->prec)
		fmt->prec = len;
	wsps = fmt->w_fild - fmt->prec;
	if (fmt->minus)
	{
		put_some_n(s, 0, fmt->prec);
		put_some_n(s, ' ', wsps);
	}
	else
	{
		put_some_n(s, ' ', wsps);
		put_some_n(s, 0, fmt->prec);
	}
	return (fmt->w_fild);
}

int print_char(char c, t_format *fmt)
{
	int		wsps;

	if (!fmt->prec)
		fmt->prec = 1;
	wsps = fmt->w_fild - fmt->prec;
	if (fmt->minus)
	{
		put_some_n(0, c, fmt->prec);
		put_some_n(0, ' ', wsps);
	}
	else
	{
		put_some_n(0, ' ', wsps);
		put_some_n(0, c, fmt->prec);
	}
	return (fmt->w_fild);
}



