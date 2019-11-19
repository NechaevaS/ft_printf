/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:04:32 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/18 17:06:23 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 
  
  
int main()
{
  
//unsigned long long t = 0xDEADBEAFull;
    //unsigned long long int n = 0xFFFFAAAAFFFFull;
  // char *str = "hello";
  // char *str1 = "hello";
  // ft_printf("my %-10.4llX\n",t);
  //   printf("or %-10.4llX\n", t); 
  // printf("\nret (%d)\n", ft_printf("%#.o", 0));
  // printf("%#.o\n", 0);
  //   printf("\nret (%d)\n", ft_printf("%#.5o", 5263));
  // printf("%#.5o\n", 5263); 
  //   printf("\nret (%d)\n", ft_printf("%#.5o", 21));
  // printf("%#.5o\n", 21);
    // ft_printf("my %u, %hu, %hhu\n", 0, (unsigned short)0, (unsigned char)255);
    // printf("or %u, %hu, %hhu\n", 0, (unsigned short)0, (unsigned char)255 );
    ft_printf("my %+f\n", -3.9999999);
    printf("or %+f\n", -3.9999999);
    // ft_printf("my %#x %#o\n", 1, 1);
    // printf("or %#x %#o\n", 1, 1);
    // ft_printf("my %#x %#.o\n", 1, 1);
    // printf("or %#x %#.o\n", 1, 1);
    // ft_printf("my %f\n", 123.5e+100);
    // printf("my %f\n", 123.5e+100);
    // printf("or %#x %#.o\n", 1, 1);
    // unsigned long long int n = 18446744073709551615ull;
    // ft_putstr(ft_itoaull(n)); 
    return 0; 
}
