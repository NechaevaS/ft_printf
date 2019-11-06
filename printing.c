/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 18:13:30 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		add_wsps(int size, char str[size], t_format *fmt, int neg)
{
	int		ws;
	int		n;
    int     sign;

	sign = 0;
	if (neg || fmt->plus)
		sign = 1;
	ws = fmt->w_fild - fmt->prec - sign;
	if (fmt->add_0)
		n = '0';
	else
		n = ' ';
	ft_memset(str, n, ws);
		return (ws);
}

int		add_sign(int size, char str[size], t_format *fmt, int neg)
{
	if (neg)
	{
		*str = '-';
		return (1);
	}
	if (!neg && fmt->plus)
	{
		*str = '+';
		return (1);
	}
	return (0);
}

char	*create_prec(char *str, t_format *fmt)
{
	int     len;
	char    *prec;
	int		i;

	len = ft_strlen(str);
	if (fmt->prec)
		fmt->add_0 = 0;
	if (len > fmt->prec)
		fmt->prec = len;
	prec = (char *)malloc(sizeof(char) * fmt->prec + 1);
	ft_bzero(prec, fmt->prec);
	ft_memset(prec, '0', fmt->prec);
	i = fmt->prec - len;
	ft_memcpy(&prec[i], str, len);
	if (fmt->prec + 1 > fmt->w_fild)
		fmt->w_fild = fmt->prec + 1;
	return (prec);
}

int		put_str_fmt(int neg, char *str, t_format *fmt)
{
	int     size;
	char    *prec;
	int		wsps;
	int 	i;

	prec = create_prec(str, fmt);
	size = fmt->w_fild + 1;
	char	all_f[size];
	ft_bzero(all_f, size);
	i = 0;
	if (fmt->minus || fmt->add_0)
	{
		if (add_sign(size, all_f, fmt, neg))
			i++;
		if (fmt->add_0)
		{
			wsps = add_wsps(size, &all_f[i], fmt, neg);
			i = i + wsps;
			ft_memcpy(&all_f[i], prec , fmt->prec);
		}
		else
		{
			ft_memcpy(&all_f[i], prec , fmt->prec);
			i = i + fmt->prec;
			wsps = add_wsps(size, &all_f[i], fmt, neg);
		}
	}
	else
	{
		wsps = add_wsps(size, &all_f[i], fmt, neg);
		i = i + wsps;
		if (add_sign(size, &all_f[i], fmt, neg))
			i++;
		ft_memcpy(&all_f[i], prec , fmt->prec);
	}
	ft_putstr(all_f);
	return (ft_strlen(all_f));
}

