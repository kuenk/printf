/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 23:04:00 by dcuenca           #+#    #+#             */
/*   Updated: 2025/11/07 00:44:12 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_dtohex(const char *str, unsigned int num)
{
	int		i;
	char	*base;

	i = 0;
	if (*str == 'p' || *str == 'x')
		base = HEXA_LOW;
	else
		base = HEXA_UPP;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num < 16)
	{
		ft_putchar(base[num]);
		i++;
	}
	else
	{
		i += ft_dtohex(str, num / 16);
		ft_putchar(base[num % 16]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;
	char	aux;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
		i++;
	}
	if (n < 10)
	{
		aux = n + '0';
		ft_putchar(aux);
		i++;
	}
	else
	{
		i += ft_putnbr(n / 10);
		aux = n % 10 + '0';
		write(1, &aux, 1);
		i++;
	}
	return (i);
}

#include <limits.h>
#include <stdio.h>
int main(void)
{
	printf("original: %d\n", printf("%s %d ", "hola", 5));
	printf("proyecto: %d\n", ft_printf("%s %d ", "hola", 5));
	printf("original: %d\n", printf("%c ", 'c'));
	printf("proyecto: %d\n", ft_printf("%c ", 'c'));
	printf("original: %d\n", printf("%d ", INT_MIN));
	printf("proyecto: %d\n", ft_printf("%d ", INT_MIN));

	int z = 4;
	int *ptr = &z;
	printf("original: %d\n", printf("%p ", 0));
	printf("proyecto: %d\n", ft_printf("%p ", 0));
	printf("original: %d\n", printf("%x ", -7777));
	printf("proyecto: %d\n", ft_printf("%x ", -7777));
	printf("original: %d\n", printf("%X ", 9223372036854775807LL));
	printf("proyecto: %d\n", ft_printf("%X ", 9223372036854775807LL));
	printf("original: %d\n", printf("%u ", -3647));
	printf("proyecto: %d\n", ft_printf("%u ", -3647));
	printf("original: %d\n", printf("%% "));
	printf("proyecto: %d\n", ft_printf("%% "));

	return(0);
}