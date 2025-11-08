/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:45:52 by dcuenca           #+#    #+#             */
/*   Updated: 2025/11/07 00:43:36 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(size_t n)
{
	int		i;
	char	aux;

	i = 0;
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

int	ft_select_type(char const *format, va_list args)
{
	char	*aux;
	size_t	hex;

	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*format == 's')
	{
		aux = va_arg(args, char *);
		if (aux == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
		ft_putstr(aux);
		return (ft_strlen(aux));
	}
	if (*format == 'p')
	{
		hex = va_arg(args, unsigned long);
		if (hex == 0)
		{
			ft_putstr("(nil)");
			return (5);
		}
		ft_putstr("0x");
		return (ft_putpointer(format, hex) + 2);
	}
	return (0);
}

int	ft_select_type2(char const *format, va_list args)
{
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*format == 'x' || *format == 'X')
		return (ft_dtohex(format, va_arg(args, unsigned int)));
	if (*format == 'u')
		return (ft_putuns(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			i += ft_select_type(str, args);
			i += ft_select_type2(str, args);
		}
		else
		{
			ft_putchar(str[0]);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}

#include <stdio.h>
int main(void)
{
	printf("original: %d\n", printf("%s ", "hola"));
	printf("proyecto: %d\n", ft_printf("%s ", "hola"));
	printf("original: %d\n", printf("%c ", 'c'));
	printf("proyecto: %d\n", ft_printf("%c ", 'c'));
	printf("original: %d\n", printf("%d ", 3647));
	printf("proyecto: %d\n", ft_printf("%d ", 3647));

	int z = 4;
	int *ptr = &z;
	printf("original: %d\n", printf("%p ", ptr));
	printf("proyecto: %d\n", ft_printf("%p ", ptr));
	printf("original: %d\n", printf("%x ", -7777));
	printf("proyecto: %d\n", ft_printf("%x ", -7777));
	printf("original: %d\n", printf("%X ", -7777));
	printf("proyecto: %d\n", ft_printf("%X ", -7777));
	printf("original: %d\n", printf("%u ", 3647));
	printf("proyecto: %d\n", ft_printf("%u ", 3647));

	return(0);
}
