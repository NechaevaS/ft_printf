/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:04:32 by snechaev          #+#    #+#             */
/*   Updated: 2019/11/14 16:13:09 by snechaev         ###   ########.fr       */
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
    printf("\nret (%d)\n", ft_printf("%#.5o", 21));
  printf("%#.5o\n", 21); 
    // ft_printf("my %8.3f\n", 1.123456789);
    // printf("or %8.3f\n", 1.123456789);
    // unsigned long long int n = 18446744073709551615ull;
    // ft_putstr(ft_itoaull(n)); 
    return 0; 
}
