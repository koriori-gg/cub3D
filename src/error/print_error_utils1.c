/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:33:23 by ihashimo          #+#    #+#             */
/*   Updated: 2023/07/16 13:24:52 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

ssize_t	ft_putchar_stderr(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

ssize_t	ft_putstr_stderr(char *s)
{
	if (!s)
		return (ft_putstr_stderr("(null)"));
	return (write(STDERR_FILENO, s, ft_strlen(s)));
}

ssize_t	ft_putnbr_stderr(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_stderr('-');
	}
	if (num >= 10)
	{
		ft_putnbr_stderr(num / 10);
		ft_putchar_stderr((num % 10) + 48);
	}
	else
		ft_putchar_stderr(num + 48);
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
