/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliar_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:10:06 by dcuenca           #+#    #+#             */
/*   Updated: 2025/11/08 21:10:11 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putpointer(const char *str, unsigned long num)
{
	int		i;
	char	*base;

	i = 0;
	base = HEXA_LOW;
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