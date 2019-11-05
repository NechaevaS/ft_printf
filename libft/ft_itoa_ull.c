/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:02:07 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 16:44:20 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *s, unsigned long long int n)
{
	if (n > 9)
		s = ft_fill(s, n / 10);
	*s = (n % 10) + '0';
	return (s + 1);
}

char		*ft_itoaull(unsigned long long int n)
{
	char	*str;

	str = ft_strnew(21);
	if (!str)
		return (NULL);
	ft_fill(str, n);
	return (str);
}
