/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:49:23 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 11:40:18 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest < src)
	{
		i = 0;
		while (i++ < n)
			d[i - 1] = s[i - 1];
	}
	else if (src < dest)
	{
		i = n;
		while (0 < i--)
			d[i] = s[i];
	}
	return (dest);
}
/*
int main(void)
{
	char *dst = malloc(100);
	dst = "abcdefghijhklmnopadfghkjhgfdsdfghjhgfdsasdfg";
	ft_memmove(dst + 3, dst, 10000);

}
*/
/*
int	main(void)
{
	char *src = malloc(100);
	for (int i = 0; i < 100; i++)
		src[i] = i;
	char *dst = malloc(100);
	dst = "abcdefghijhklmnopadfghkjhgfdsdfghjhgfdsasdfg";
	printf("%s\n",dst);
	ft_memmove(dst + 3, dst, 9);
	printf("%s\n",dst);
	return (0);
}
*/

//dest<srcの時場合分け必要かも
/*
int main(void)
{
	char buf[50] = "ABCDDEFG";
	memmove(buf+3,buf,3);
	printf("コピー後のbuf文字列→%s\n",buf);

	char buf1[50] = "ABCDDEFG";
	ft_memmove(buf1+3,buf1,3);
	printf("コピー後のbuf文字列→%s\n",buf1);

	return 0;
}
*/