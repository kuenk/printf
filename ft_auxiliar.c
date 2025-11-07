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

#include "printf.h"

int ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

void	ft_putstr(const char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
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

int ft_dtohex(const char *str, unsigned long num)
{
	int i;
	char    *base;

	i = 0;
	if (*str == 'p' || *str == 'x')
		base = HEXA_LOW;
	else
		base = HEXA_UPP;
	if (num == 0)
	{
		ft_putchar('0', 1);
		return (1);
	}
	if (num < 16)
	{
		ft_putchar(base[num], 1);
		i++;
	}
	else
	{
		i += ft_dtohex(str, num / 16);
		ft_putchar(base[num % 16], 1);
		i++;
	}
	return (i);
}

