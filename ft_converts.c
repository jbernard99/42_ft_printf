/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:26:50 by jbernard          #+#    #+#             */
/*   Updated: 2021/09/23 17:26:52 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_int(va_list args)
{
	int	i;

	i = va_arg(args, int);
	ft_putnbr_fd(i, 1);
	if (i < 0)
		return (ft_intlen(i * -1) + 1);
	return (ft_intlen(i));
}

int	convert_uint(const char *str, va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if (*str == 'c')
	{
		ft_putchar_fd(i, 1);
		return (1);
	}
	else if (*str == 'u')
	{
		ft_putunbr_fd(i, 1);
		return (ft_intlen(i));
	}
	return (0);
}

int	convert_txt(const char *str, va_list args)
{
	char	*txt;

	if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	txt = va_arg(args, char *);
	if (txt == NULL)
		return (ft_putstr_fd_len("(null)", 1));
	else
		return (ft_putstr_fd_len(txt, 1));
}

int	convert_hexa(const char *str, va_list args)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if ((int)i < 0)
		i = i + 18446744073709551615U + 1;
	if (*str == 'x')
		return (ft_putstr_fd_len(ft_dectohex(i, 0), 1));
	if (*str == 'X')
		return (ft_putstr_fd_len(ft_dectohex(i, 1), 1));
	return (0);
}

int	convert_pointer(va_list args)
{	
	unsigned long long	i;

	i = va_arg(args, unsigned long long);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	return (ft_putstr_fd_len(ft_dectohex(i, 0), 1) + 2);
}
