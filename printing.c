/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/06 17:00:54 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

int		add_prefix(int size, char str[size], t_format *fmt)
{
	if (fmt->conv == 'p' || fmt->flags == '#')
	{
		*str = '0';
		if (fmt->conv == 'X')
			*(str + 1) = 'X';
		if (fmt->conv == 'x' || fmt->conv == 'p')
			*(str + 1) = 'x';
		return (2);
	}
	if (fmt->conv == 'o')
	{
		*str = '0';
		return (1);
	}
	return (0);
}

void	fill_prec(char *str, t_format *fmt, char prec[fmt->prec])
{
	int     len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (fmt->conv == 's' && fmt->prec)
		len = fmt->prec;
	if (fmt->prec)
		fmt->add_0 = 0;
	if (len > fmt->prec)
		fmt->prec = len;
	ft_bzero(prec, fmt->prec);
	ft_memset(prec, '0', fmt->prec);
	i = fmt->prec - len;
	ft_memcpy(&prec[i], str, len);
	if (fmt->prec > fmt->w_fild)
		fmt->w_fild = fmt->prec;
}

int		put_result(int neg, char *str, t_format *fmt)
{
	int 	i;
	char	prec[fmt->prec + 1];
	char	all_f[fmt->w_fild + 1];
	
	fill_prec(str, fmt, prec);
	all_f[fmt->w_fild] = '\0';
	ft_memset(all_f, fmt->fill, fmt->w_fild);
	i = 0;
	if (fmt->minus || fmt->add_0)
	{
		if (add_sign(fmt->w_fild, all_f, fmt, neg))
			i++;
		if (fmt->add_0)
		{
			i = fmt->w_fild - fmt->prec;
			ft_memcpy(&all_f[i], prec , fmt->prec);
		}
		else
			ft_memcpy(&all_f[i], prec , fmt->prec);
	}
	else
	{
		i = fmt->w_fild - fmt->prec;
		i = i + add_sign(fmt->w_fild, &all_f[i], fmt, neg);
		i = i + add_prefix(&all_f[i + 1], prec , fmt->prec);
		ft_memcpy(&all_f[i + 3], prec , fmt->prec);
	}
	ft_putstr(all_f);
	return (ft_strlen(all_f));
}

