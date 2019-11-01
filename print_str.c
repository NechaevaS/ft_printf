/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:56:02 by snechaev          #+#    #+#             */
/*   Updated: 2019/10/31 17:46:57 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_str(va_list *va_l, t_format *fmt)
{
	void	*c;
	int     len;
	int		wsps;
	int		i;

	i = 0;
	c = (char *)va_arg(*va_l, void *);
	len = fmt->prec;
	wsps = fmt->w_fild - ft_strlen(c);
	if (fmt->minus)
	{
		while(i < len)
		{
			write(1, &c[i], 1);
			i++;
		}
		while(wsps > 0)
		{
			write(1, " ", 1);
			wsps--;
		}
	}
	return (fmt->w_fild);
}