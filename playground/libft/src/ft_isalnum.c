/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:48:49 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int d)
{
	return (ft_isalpha(d) || ft_isdigit(d));
}
/*
int main(void)
{
    printf("%d\n",ft_isalnum('9'));
	printf("%d\n",ft_isalnum('A'));
	printf("%d\n",ft_isalnum('z'));
	printf("%d\n",ft_isalnum(' '));
	return 0;
}
*/