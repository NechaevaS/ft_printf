/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:05:37 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 18:03:58 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct
{
	char        flags;
	int         alt_fmt;
	int         plus;
	int         minus;
	int         add_0;
	int         w_fild;
	int         prec;
	enum mod_l {hh, h, l, ll, L} len;
	char         conv;
}               t_format;

int				ft_printf(const char *format, ...);
t_format        *init();
int             arg_parse(const char **arg, t_format *fmt);
int             print_args(va_list *va_l, t_format *fmt);
void			put_some_n(char *str, char c, int n);
// int             print_int(va_list *va_l, t_format *fmt);
// int             print_char(va_list *va_l, t_format *fmt);
// int             print_okt(va_list *va_l, t_format *fmt);
// int             print_dec(va_list *va_l, t_format *fmt);
// int             print_hex(va_list *va_l, t_format *fmt);
// int             print_ptr(va_list *va_l, t_format *fmt);
// int             print_double(va_list *va_l, t_format *fmt);
int             print_str(char *s, t_format *fmt);
int 			print_char(char c, t_format *fmt);
int				print_int(va_list *va_l, t_format *fmt);
int				print_uox(va_list *va_l, t_format *fmt);
int				put_str_fmt(int d, char *str, t_format *fmt);


#endif