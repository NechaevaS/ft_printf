/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:04:32 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/04 17:57:49 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 
  
  
int main() 
{
 //   unsigned long long int n = 18446744073709551615ull;
    ft_printf("my %d\n", -15);
    printf("or %d\n", -15); 
    // ft_printf("my %8.3f\n", 1.123456789);
    // printf("or %8.3f\n", 1.123456789);
    // unsigned long long int n = 18446744073709551615ull;
    // ft_putstr(ft_itoaull(n)); 
    return 0; 
}
