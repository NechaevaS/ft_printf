/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:04:32 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/08 16:39:43 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 
  
  
int main()
{
//unsigned long long t = 0xDEADBEAFull;
    //unsigned long long int n = 0xFFFFAAAAFFFFull;
//  char *str = "hello";
  // ft_printf("my %-10.4llX\n",t);
  //   printf("or %-10.4llX\n", t); 
  printf("\nret (%d)\n", ft_printf("%7.7s%7.7s", "hello", "world"));
  printf("%7.7s%7.7s", "hello", "world"); 
    // ft_printf("my %8.3f\n", 1.123456789);
    // printf("or %8.3f\n", 1.123456789);
    // unsigned long long int n = 18446744073709551615ull;
    // ft_putstr(ft_itoaull(n)); 
    return 0; 
}
