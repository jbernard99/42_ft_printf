/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:27:11 by jbernard          #+#    #+#             */
/*   Updated: 2021/09/23 17:27:15 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:14:45 by jbernard          #+#    #+#             */
/*   Updated: 2021/08/18 22:14:48 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		manage(const char *str, va_list args);

int		convert_uint(const char *str, va_list args);
int		convert_txt(const char *str, va_list args);
int		convert_int(va_list args);
int		convert_hexa(const char *str, va_list args);
int		convert_pointer(va_list args);

int		ft_putstr_fd_len(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(char *str);
char	*ft_strrev(char *str);
int		ft_intlen(unsigned int x);
char	*ft_dectohex(unsigned long long n, int capitalize);
int		ft_printf(const char *str, ...);

#endif
