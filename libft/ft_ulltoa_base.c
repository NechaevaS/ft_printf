#include "libft.h"

char *ft_ulltoa_base(char *s, unsigned long long n, unsigned base)
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
