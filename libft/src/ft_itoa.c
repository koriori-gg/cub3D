/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:10 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lennum(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	len;
	long	num;

	num = (long)n;
	len = ft_lennum(n);
	dest = malloc(sizeof(char) *(len + 1));
	if (!dest)
		return (0);
	if (num < 0)
	{
		dest[0] = '-';
		num = -num;
	}
	if (num == 0)
		dest[0] = '0';
	dest[len--] = '\0';
	while (num)
	{
		dest[len] = ((num % 10) + 48);
		num /= 10;
		len--;
	}
	return (dest);
}
/*
int main(void)
{
    char *ans =ft_itoa(-2147483648);
    printf("%s\n",ans);
    char *ans1 =ft_itoa(2147483647);
    printf("%s\n",ans1);
    char *ans2 =ft_itoa(0);
    printf("%s\n",ans2);
    return 0;
}
*/