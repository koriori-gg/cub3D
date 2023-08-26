/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:48:59 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int d)
{
	return ((0 <= d && d <= 127));
}
/*
int main(void)
{
    printf("%d\n",ft_isascii('9'));
	printf("%d\n",ft_isascii('A'));
	printf("%d\n",ft_isascii('z'));
	printf("%d\n",ft_isascii(128));
	return 0;
}
*/