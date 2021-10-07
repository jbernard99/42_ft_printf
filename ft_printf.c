/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:27:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/09/23 17:27:01 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage(const char *str, va_list args)
{
	int	size;

	size = 0;
	if (*str == 's' || *str == '%')
		size = convert_txt(str, args) + size;
	else if (*str == 'u' || *str == 'c')
		size = convert_uint(str, args) + size;
	else if (*str == 'd' || *str == 'i')
		size = convert_int(args) + size;
	else if (*str == 'x' || *str == 'X')
		size = convert_hexa(str, args) + size;
	else if (*str == 'p')
		size = convert_pointer(args) + size;
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	va_start(args, str);
	size = 0;
	while (*str)
	{
		while (*str && *str != '%')
		{
			write(1, str++, 1);
			size++;
		}
		if (*str == '%')
		{
			str++;
			size = manage(str, args) + size;
			str++;
		}
	}
	return (size);
}
