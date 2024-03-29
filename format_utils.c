/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:08:42 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 16:58:24 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_size(int neg, t_format *fmt, t_print *p)
{
	int max;
	int len1;

	len1 = p->size_prec;
	if ((fmt->conv == 'd' || fmt->conv == 'f') && (neg || fmt->plus || fmt->sps))
		len1++;
	if (p->pref)
	{
		if (fmt->conv == 'x' || fmt->conv == 'X' || fmt->conv == 'p')
			len1 = len1 + 2;
		else
			len1 = len1 + 1;
	}
	if (len1 > fmt->w_fild)
		max = len1;
	else
		max = fmt->w_fild;
	return (max);
}

void	init_fmt(t_format *fmt)
{
	fmt->alt_fmt = 0;
	fmt->plus = 0;
	fmt->minus = 0;
	fmt->sps = 0;
	fmt->add_0 = 0;
	fmt->w_fild = 0;
	fmt->is_prec = 0;
	fmt->prec = 0;
	fmt->conv = 0;
	fmt->len = non;
}

void	mod_p_altf(t_format *fmt, t_print *p)
{
	if (ft_strcmp(p->str, "0") && fmt->conv != 'f')
		p->pref = 1;
	if (!ft_strcmp(p->str, "0") && fmt->conv == 'o')
	{
		p->pref = 1;
		if (p->size_prec == 1)
			p->size_prec = 0;
	}
	if (fmt->prec > 0 && fmt->conv == 'o' && (fmt->prec > p->len))
		p->pref = 0;
}

void	modify_p(int neg, t_format *fmt, t_print *p)
{
	if (neg && fmt->plus)
		fmt->plus = 0;
	if (fmt->conv == 'c' && p->len == 0)
		p->len = 1;
	if ((fmt->conv == 'd' || fmt->conv == 'o' || fmt->conv == 'X' || fmt->conv == 'x' || fmt->conv == 'u') && !ft_strcmp(p->str, "0") && fmt->is_prec && !fmt->prec)
		p->len = 0;
	if ((fmt->conv == 's' && (fmt->prec > p->len || !fmt->is_prec)))
		p->size_prec = p->len;
	else if (fmt->conv != 's' && p->len > fmt->prec)
		p->size_prec = p->len;
	else
		p->size_prec = fmt->prec;
	if (fmt->add_0)
		p->fill_a = '0';
	if (fmt->conv == 'p' && ft_strcmp(p->str, "(nil)"))
		p->pref = 1;
	if (fmt->alt_fmt)
		mod_p_altf(fmt, p);
	p->size_all = get_size(neg, fmt, p);
	if (neg)
		p->neg = 1;
	if (fmt->conv == 's')
		p->fill_p = ' ';
}

void	init_p(int neg, char *str, t_format *fmt, t_print *p)
{
	p->str = str;
	p->len = ft_strlen(p->str);
	p->size_prec = 0;
	p->size_all = 0;
	p->fill_a = ' ';
	p->fill_p = '0';
	p->pref = 0;
	p->neg = 0;
	modify_p(neg, fmt, p);
}
