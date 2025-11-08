/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:40:12 by dcuenca           #+#    #+#             */
/*   Updated: 2025/11/07 00:30:29 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"

int		ft_printf(char const *str, ...);
int		ft_putchar(char c);
int 	ft_putstr(const char *s);
size_t	ft_strlen(const char *str);
int		ft_dtohex(const char *str, unsigned int num);
int		ft_putnbr(int n);
int	    ft_putuns(size_t n);
int	    ft_putpointer(const char *str, unsigned long num);

#endif