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
	if (fmt->conv != 'd' && fmt->conv != 'f')
		return (0);
	if (p->neg)
	{
		*str = '-';
		return (1);
	}
	if (fmt->plus)
	{
		*str = '+';
		return (1);
	}
	if (fmt->sps)
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

char	*fill_prec(t_print *p, t_format *fmt)
{
	int	i;
	char *prec;

	prec = (char *)malloc(sizeof(char) * p->size_prec + 1);
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
	return (prec);
}

void	print_def(t_format *fmt, t_print *p, char *all_f, char *prec)
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

void	put_all_f(char *all_f, t_print *p)
{
	int i;
	
	i = 0;
	while (i < p->size_all)
	{
		write(1, &all_f[i], 1);
		i++;
	}
//	free(all_f);
}

int		put_result(int neg, char *str, t_format *fmt)
{
	t_print	p;
	int		i;
	char	*prec;
	char	*all_f;

	init_p(neg, str, fmt, &p);
	prec = fill_prec(&p, fmt);
	all_f = (char *)malloc(sizeof(char) * p.size_all + 1);
	ft_memset(all_f, 0, p.size_all + 1);
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
	put_all_f(all_f, &p);
//	free(prec);
	return (p.size_all);
}
