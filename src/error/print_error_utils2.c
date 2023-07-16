/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:33:25 by ihashimo          #+#    #+#             */
/*   Updated: 2023/07/16 13:24:52 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

ssize_t	utoa_stderr(unsigned long nbr, unsigned long n, char *asc)
{
	ssize_t		count;

	count = 0;
	if (nbr >= n)
		count += utoa_stderr(nbr / n, n, asc);
	count += ft_putchar_stderr(asc[nbr % n]);
	return (count);
}

ssize_t	ft_putvoid_stderr(void *s)
{
	unsigned long	ucs;
	ssize_t			count;

	ucs = (unsigned long)s;
	count = ft_putstr_stderr("0x");
	if (count == -1)
		return (-1);
	return (count + utoa_stderr(ucs, 16, "0123456789abcdef"));
}
