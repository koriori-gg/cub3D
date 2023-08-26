/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:48:54 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int d)
{
	return (('a' <= d && d <= 'z') || ('A' <= d && d <= 'Z'));
}
/*
int main(void)
{
    printf("%d\n",ft_isalpha('9'));
	printf("%d\n",ft_isalpha('A'));
	printf("%d\n",ft_isalpha('z'));
	printf("%d\n",ft_isalpha(128));
	return 0;
}
*/