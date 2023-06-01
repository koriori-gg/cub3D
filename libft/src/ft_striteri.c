/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:03 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void test(unsigned int i, char *c)
{
	unsigned int k;

	k = 0;
	while(k < i)
	{
		if ('a' <= c[k] && c[k] <= 'z')
			c[k] -= 32;
		k++;
	}
}

int main(void)
{
	void (*pfunc)(unsigned int, char*);
	char s[] = "abcdefghijk01234";
	//char *s[] = {"abcd","efgh","ijkl","OPqr","stuvwxyz"};

	pfunc = test;
	ft_striteri(s, pfunc);
	printf("%s",s);
	
	//int i = 0;
	//while(s[i] != (void *)'\0')
	//   printf("%s",s[i++]);
	
	return 0;
}
*/