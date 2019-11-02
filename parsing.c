/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:56:38 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/01 11:05:09 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_parse(const char **arg, t_format *fmt)
{
	while (1)
	{
		if (**arg == '-')
			fmt->minus = 1;
		else if (**arg == '+')
			fmt->plus = 1;
		else if (**arg == '#')
			fmt->alt_fmt = 1;
		else if (**arg == '0')
			fmt->add_0 = 1;
		else
			break ;
		(*arg)++;
	}
	if (fmt->add_0 && fmt->minus)
		fmt->add_0 = 0;
}

void	wfild_parse(const char **arg, t_format *fmt)
{
	while (ft_isdigit(**arg))
	{
		fmt->w_fild = fmt->w_fild * 10 + ((**arg) - '0');
		(*arg)++;
	}
}

void	prec_parse(const char **arg, t_format *fmt)
{
	if (**arg == '.')
	{
		(*arg)++;
		while (ft_isdigit(**arg))
		{
			fmt->prec = fmt->prec * 10 + ((**arg) - '0');
			(*arg)++;
		}
	}
}

void	mod_l_parse(const char **arg, t_format *fmt)
{
	if (**arg == 'h' && *(*arg + 1) == 'h')
		fmt->len = hh;
	else if (**arg == 'h')
		fmt->len = h;
	if (**arg == 'l' && *(*arg + 1) == 'l')
		fmt->len = ll;
	else if (**arg == 'l')
		fmt->len = l;
	if (**arg == 'L')
		fmt->len = L;
}

int	arg_parse(const char **arg, t_format *fmt)
{
	int			len;

	len = 0;
	(*arg)++;
	flags_parse(arg, fmt);
	wfild_parse(arg, fmt);
	prec_parse(arg, fmt);
	mod_l_parse(arg, fmt);
	fmt->conv = **arg;

	return (len);
}