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

#include "printf.h"

int	ft_select_type(char const *format, va_list args)
{
	char	*aux;

	if (*format == 'c')
		return (ft_putchar(va_arg(args, int), 1));
	if (*format == 's')
	{
		aux = va_arg(args, char *);
		if (aux == NULL)
		{
			ft_putstr("(null)", 1);
			return (6);
		}
		ft_putstr(aux, 1);
		return (ft_strlen(aux));
	}
	if (*format == 'p')
	{
		ft_putstr("0x", 1);
		return (ft_dtohex(format, va_arg(args, unsigned long)) + 2);
	}
/*		ft_
	if (*format == 'd')
		ft_digito
	if (*format == 'i')
	if (*format == 'u')
	if (*format == 'x' || *format == 'X')
		ft_hexadecimal
	if (*format == '%')*/
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
		}
		else
		{
			ft_putchar(str[0], 1);
			i++;
		}
		str++;
	}
	va_end(args);
	return (i);
}