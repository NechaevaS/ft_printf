/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:41:22 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 14:41:44 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(char *s, unsigned long long n, unsigned base)
{
	int rem;

	if (n > base - 1)
		s = ft_ulltoa_base(s, n / base, base);
	rem = n % base;
	if (rem < 10)
		*s = rem + '0';
	else
		*s = rem - 10 + 'a';
	return (s + 1);
}
