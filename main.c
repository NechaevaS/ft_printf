/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:04:32 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/06 16:46:05 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 
  
  
int main() 
{
//   unsigned long long int n = 1844674407370955161ull;
    //unsigned long long int n = 0xFFFFAAAAFFFFull;
  char *str = "hello";

    ft_printf("my %20p\n", &str);
    printf("or %o\n", 189); 
    // ft_printf("my %8.3f\n", 1.123456789);
    // printf("or %8.3f\n", 1.123456789);
    // unsigned long long int n = 18446744073709551615ull;
    // ft_putstr(ft_itoaull(n)); 
    return 0; 
}
