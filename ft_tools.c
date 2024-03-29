/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:27:33 by jbernard          #+#    #+#             */
/*   Updated: 2021/09/23 17:27:34 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(unsigned int x)
{
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		size;
	int		i;
	char	*ret;

	size = ft_strlen(str);
	ret = malloc((size + 1) * sizeof(char));
	if (size == 1)
	{
		ret[0] = str[0];
		ret[1] = '\0';
		return (ret);
	}
	size--;
	i = 0;
	while (size >= 0)
		ret[i++] = str[size--];
	ret[i] = '\0';
	return (ret);
}

char	*ft_dectohex(unsigned long long n, char *base)
{
	int		temp;
	char	rtrn[99];
	char	*ptr;
	int		i;

	if (n == 0)
	{
		ptr = malloc(2 * sizeof(char));
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	i = 0;
	while (n > 0)
	{
		temp = n % 16;
		rtrn[i++] = base[temp];
		n = n / 16;
	}
	rtrn[i] = '\0';
	ptr = ft_strrev(rtrn);
	return (ptr);
}
