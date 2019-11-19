/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:12:35 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 17:20:05 by snechaev         ###   ########.fr       */
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
	if (fmt->sps && (!p->neg || (fmt->conv == 's' && p->len == 0)))
	{
		*str = ' ';
		return (1);
	}
	return (0);
}

int		add_prefix(int size, char str[size], t_format *fmt, t_print *p)
{
	if (p->pref)
	{
		if (fmt->conv == 'p' || (fmt->alt_fmt && fmt->conv != 'o'
			&& fmt->conv != 'f'))
		{
			*(str) = '0';
			if (fmt->conv == 'x' || fmt->conv == 'p')
				*(str + 1) = 'x';
			if (fmt->conv == 'X')
				*(str + 1) = 'X';
			return (2);
		}
		if (fmt->conv == 'o' && fmt->alt_fmt)
		{
			*str = '0';
			return (1);
		}
	}
	return (0);
}

void	fill_prec(t_print *p, t_format *fmt, char prec[fmt->prec + 1])
{
	int	i;

	i = 0;
	ft_bzero(prec, p->size_prec + 1);
	ft_memset(prec, p->fill_p, p->size_prec);
	if (fmt->conv == 'X')
	{
		while (p->str[i])
		{
			if (p->str[i] >= 'a' && p->str[i] <= 'z')
				p->str[i] = p->str[i] - 32;
			i++;
		}
	}
	if (p->size_prec > p->len)
	{
		i = p->size_prec - p->len;
		ft_memcpy(&prec[i], p->str, p->len);
	}
	else
		ft_memcpy(&prec[0], p->str, p->size_prec);
}

void	print_def(t_format *fmt, t_print *p, char all_f[p->size_all + 1],
	char prec[p->size_prec + 1])
{
	int i;

	i = p->size_all - p->size_prec;
	ft_memcpy(&all_f[i], prec, p->size_prec);
	if (p->pref && !fmt->add_0)
	{
		if (fmt->conv == 'o')
			i--;
		else
			i = i - 2;
		add_prefix(p->size_all, &all_f[i], fmt, p);
	}
	if (fmt->add_0)
	{
		if (fmt->plus || p->neg || fmt->sps)
		{
			add_sign(p->size_all, &all_f[0], fmt, p);
			add_prefix(p->size_all, &all_f[1], fmt, p);
		}
		else
			add_prefix(p->size_all, &all_f[0], fmt, p);
	}
	else
		i = i - (add_sign(p->size_all, &all_f[i - 1], fmt, p));
}

int		put_result(int neg, char *str, t_format *fmt)
{
	t_print	p;
	int		i;

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
		i = i + (add_prefix(p.size_all, &all_f[i], fmt, &p));
		ft_memcpy(&all_f[i], prec, p.size_prec);
	}
	else
		print_def(fmt, &p, all_f, prec);
	i = 0;
	while (i < p.size_all)
	{
		write(1, &all_f[i], 1);
		i++;
	}
	return (p.size_all);
}
