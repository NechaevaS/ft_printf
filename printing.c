/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/11 15:47:14 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		add_sign(int size, char str[size], t_format *fmt, t_print *p)
{
	if (p->neg)
	{
		*str = '-';
		return (1);
	}
	if (!p->neg && fmt->plus)
	{
		*str = '+';
		return (1);
	}
	return (0);
}

int		add_prefix(int size, char str[size], t_format *fmt)
{
	if (fmt->conv == 'p' || fmt->alt_fmt)
	{
		*(str) = '0';
		if (fmt->conv == 'x' || fmt->conv == 'p')
			*(str + 1) = 'x';
		if (fmt->conv == 'X')
			*(str + 1) = 'X';
		return (2);
	}
	if (fmt->conv == 'o')
	{
		*str = '0';
		return (1);
	}
	return (0);
}

void	fill_prec(t_print *p, t_format *fmt, char prec[fmt->prec + 1])
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(p->str);
	ft_bzero(prec, p->size_prec + 1);
	ft_memset(prec, p->fill_p, p->size_prec);
	if (fmt->conv == 'X')
	{
		while(p->str[i])
		{
			p->str[i] = p->str[i] - 32;
			i++;
		}
	}
	if (p->size_prec > len)
	{
		i = p->size_prec - len;
		ft_memcpy(&prec[i], p->str, len);
	}
	else
		ft_memcpy(&prec[0], p->str, p->size_prec);
}

int		put_result(int neg, char *str, t_format *fmt)
{
	int 	i;
	t_print	p;
	
	init_p(neg, str, fmt, &p);
	char	prec[p.size_prec + 1];
	fill_prec(&p, fmt, prec);
	char	all_f[p.size_all + 1];
	all_f[p.size_all] = '\0';
	ft_memset(all_f, p.fill_a, p.size_all);
	i = 0;
	if (fmt->minus)
	{
		i = i + (add_sign(p.size_all, &all_f[0], fmt, &p));
		i = i + (add_prefix(p.size_all, &all_f[i], fmt));
		ft_memcpy(&all_f[i], prec , p.size_prec);
	}
	else
	{
		i = p.size_all - p.size_prec;
		ft_memcpy(&all_f[i], prec , p.size_prec);
		if (p.pref)
		{
			if (fmt->conv == 'o')
				i--;
			else
				i = i - 2;	
			add_prefix(p.size_all, &all_f[i], fmt);
		}
		if (fmt->add_0)
			add_sign(p.size_all, &all_f[0], fmt, &p);
		else
			i = i - (add_sign(p.size_all, &all_f[i - 1], fmt, &p));
	}
	ft_putstr(all_f);
	return (p.size_all);
}
