/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:52:36 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 11:11:54 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
*/
ssize_t	ft_putchar_std(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr_std(char *s)
{
	if (!s)
		return (ft_putstr_std("(null)"));
	return (write(1, s, ft_strlen(s)));
}

ssize_t	ft_putnbr_std(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_std('-');
	}
	if (num >= 10)
	{
		ft_putnbr_std(num / 10);
		ft_putchar_std((num % 10) + 48);
	}
	else
		ft_putchar_std(num + 48);
	if (n >= 0)
		return (ft_nbrdigits(n, 10));
	else
		return (ft_nbrdigits(n, 10) + 1);
}

ssize_t	ft_nbrdigits(int nbr, int n)
{
	ssize_t	digit;

	digit = 0;
	if (nbr == 0)
		digit++;
	while (nbr)
	{
		digit++;
		nbr = nbr / n;
	}
	return (digit);
}
