/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:47:49 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(long num, const char *nptr, size_t i, int sign)
{
	long	n;

	n = nptr[i] - 48;
	if (sign == -1 && sign * num > (LONG_MAX - n) / 10)
		return (-1);
	if (sign == 1 && sign * num < (LONG_MIN + n) / 10)
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = -1;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		sign = sign * (44 - nptr[i]);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (overflow(num, nptr, i, sign) != 1)
			return (overflow(num, nptr, i, sign));
		num = num * 10 - (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}
/*
int	main(void)
{
	printf("%d,%d\n",ft_atoi("--12"),atoi("--12"));
	printf("%d\n",ft_atoi("9223372036854775808"));
	printf("%d\n",ft_atoi("9223372036854775809"));
	printf("%d\n",ft_atoi("9223372036854775810"));
	printf("%d\n",atoi("9223372036854775808"));
	printf("%d\n",ft_atoi("-33"));
	printf("%d\n",ft_atoi("1"));
	printf("%d,%d\n",ft_atoi("1"), atoi("1"));
}
*/
/*
int	main(void)
{
	char str[]="  ---+--+1234ab567";
	int ans =ft_atoi(str);
	printf("ans:%d\n",ans);

	char str1[]="  \t\n\v\f\r---+--+1234ab567";
	int ans1 =ft_atoi(str1);
	printf("ans:%d\n",ans1);

	char str2[]="-2147483648";
	int ans2 =ft_atoi(str2);
	printf("ans:%d\n",ans2);

	char str3[]="2147483647";
	int ans3 =ft_atoi(str3);
	printf("ans:%d\n",ans3);

	return 0;
}
*/