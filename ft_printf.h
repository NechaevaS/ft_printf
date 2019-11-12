/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:05:37 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/11 12:40:13 by snechaev         ###   ########.fr       */
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
	int         alt_fmt;
	int         plus;
	int         minus;
	int         add_0;
	int         w_fild;
	int			is_prec;
	int         prec;
	enum mod_l {hh, h, l, ll, L} len;
	char         conv;
}               t_format;

typedef struct
{
	char        *str;
	char		fill_a;
	char		fill_p;
	int			pref;
	int         size_all;
	int         size_prec;
	int         neg;
}               t_print;

int				ft_printf(const char *format, ...);
void			init_fmt(t_format *fmt);
void 			init_p(int neg, char *str, t_format *fmt, t_print *p);
int             arg_parse(const char **arg, t_format *fmt);
int             print_args(va_list *va_l, t_format *fmt);
int             print_str(char *s, t_format *fmt);
int 			print_char(char c, t_format *fmt);
int				print_ptr(void *p, t_format *fmt);
int				print_int(va_list *va_l, t_format *fmt);
int				print_uox(va_list *va_l, t_format *fmt);
int				print_ull(unsigned long long d, t_format *fmt);
int				print_ll(long long d, t_format *fmt);
int				put_result(int neg, char *str, t_format *fmt);


#endif