/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:22:53 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 11:12:17 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

size_t	ft_strlen(const char *str);
ssize_t	ft_putchar_std(char c);
ssize_t	ft_putstr_std(char *s);
ssize_t	ft_putnbr_std(int n);
ssize_t	ft_nbrdigits(int nbr, int n);
ssize_t	ft_utoa(unsigned long nbr, unsigned long n, char *asc);
ssize_t	ft_putvoid_std(void *s);
ssize_t	ft_check_format(const char *format, int i, va_list *args);
int		ft_printf(const char *format, ...);

#endif