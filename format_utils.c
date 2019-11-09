/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:08:42 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/08 16:53:24 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_size(int neg, t_format *fmt, t_print *p)
{
	int max;
	int len1;

    len1 = p->size_prec;
    if (neg || fmt->plus)
	    len1++;
    if (p->pref)
    {
        if (fmt->conv == 'x' || fmt->conv == 'x')
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

void init_fmt(t_format *fmt)
{
    fmt->alt_fmt = 0;
    fmt->plus = 0;
    fmt->minus = 0;
    fmt->add_0 = 0;
    fmt->w_fild = 0;
    fmt->prec = 0;
    fmt->conv = '0';
}

void init_p(int neg, char *str, t_format *fmt, t_print *p)
{
    int     len;

    p->str = str;
	len = ft_strlen(p->str);
	if (fmt->conv == 's' && fmt->prec)
		p->size_prec = fmt->prec;
	else if (len > fmt->prec)
		p->size_prec = len;
    else
        p->size_prec = fmt->prec;
    if (fmt->add_0)
        p->fill_a = '0';
    else
        p->fill_a = ' ';
   
    if (fmt->conv == 'p' || fmt->alt_fmt)
         p->pref = 1;
    else
        p->pref = 0;
	p->size_all = get_size(neg, fmt, p);
    if (neg)
        p->neg = 1;
    else
	    p->neg = 0;
    if (fmt->conv == 's')
        p->fill_p = ' ';
    else
       p->fill_p = '0'; 
}
