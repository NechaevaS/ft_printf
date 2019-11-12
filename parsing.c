/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:56:38 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/11 16:13:49 by snechaev         ###   ########.fr       */
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
		else if (**arg == '0' && fmt->minus != 1 )
			fmt->add_0 = 1;
		else
			break ;
		(*arg)++;
	}
}

void	wfild_parse(const char **arg, t_format *fmt)
{
	while (ft_isdigit(**arg) && (**arg) > 0)
	{
		fmt->w_fild = fmt->w_fild * 10 + ((**arg) - '0');
		(*arg)++;
	}
}

void	prec_parse(const char **arg, t_format *fmt)
{
	if (**arg == '.')
	{
		fmt->is_prec = 1;
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
	if (fmt->len == hh || fmt->len == ll)
		(*arg) += 2;
	else if (fmt->len == l || fmt->len == h || fmt->len == L)
		(*arg) += 1;
}

int	arg_parse(const char **arg, t_format *fmt)
{
	int			len;

	len = 0;
	(*arg)++;
	while (**arg == ' ')
		(*arg)++;
	flags_parse(arg, fmt);
	while (**arg == ' ')
		(*arg)++;
	wfild_parse(arg, fmt);
	while (**arg == ' ')
		(*arg)++;
	prec_parse(arg, fmt);
	while (**arg == ' ')
		(*arg)++;
	mod_l_parse(arg, fmt);
	while (**arg == ' ')
		(*arg)++;
	fmt->conv = **arg;
	return (len);
}