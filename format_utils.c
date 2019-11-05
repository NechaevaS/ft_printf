/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:08:42 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 14:48:12 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format *init()
{
    t_format *fmt;

    fmt = (t_format *)malloc(sizeof(t_format));
    fmt->alt_fmt = 0;
    fmt->plus = 0;
    fmt->minus = 0;
    fmt->add_0 = 0;
    fmt->w_fild = 0;
    fmt->prec = 0;
    fmt->conv = '0';
    
    return (fmt);
}
