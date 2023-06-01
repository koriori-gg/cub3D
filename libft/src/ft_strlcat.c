/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:50:14 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;

	if (size == 0)
		return (ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (size + len_src);
	ft_strlcpy(&dest[len_dest], (char *)src, size - len_dest);
	return (len_dest + len_src);
}
/*
int main()
{
	char *dst = NULL;
	const char src[9] = "ascdndms";
	printf("%zu\n",ft_strlcat(dst, src, 50));
	printf("%s",dst);
}
*/
/*
int main(void)
{
	//char *dst1 = "asdfgasdfghjklasdfghj";
	//char *dst2 = "asdfgasdfghjklasdfghj";
	char *dst1 = calloc(100, sizeof(char));
	char *dst2 = calloc(100, sizeof(char));
	char *src1 = calloc(100, sizeof(char));
	char *src2 = calloc(100, sizeof(char));
	//char *src1[100];
	//char *src2[100];
	for (int i = 0; i < 99; i++)
	{
		src1[i] = i + 1;
		src2[i] = i + 1;
	}
	printf("%zu\n",ft_strlcat(dst1, src1, 50));
	printf("%zu\n",strlcat(dst2, src2, 50));
	printf("%s\n%s",dst1,dst2);

}
*/
/*
int	main(void)
{
	char c[256] = "42tokyo";
  	printf("%lu\n",ft_strlcat(NULL  , "aiueo", 0));  // 5
	//strlenがある時点で無理じゃね感
  	//printf("%s\n",strlcat(NULL  , "aiueo", 2));  // segmentation fault
  	//printf("%s\n",strlcat(c     , NULL   , 0));  // segmentation fault
  	//printf("%s\n",strlcat(c     , NULL   , 2));  // segmentation fault
  	//printf("%s\n",strlcat(NULL  , NULL   , 0));  // segmentation fault
  	//printf("%s\n",strlcat(NULL  , NULL   , 2));  // segmentation fault
}
*/
/*
int	main(void)
{
	char dest1[50] = { "foo" };
    char src1[9] = { "bar hoge" };
	size_t size1 = 9;
	printf("lib:%zu:", strlcat(dest1, src1, size1));
	printf("%s\n", dest1);

	char dest[50] = { "foo" };
    char src[9] = { "bar hoge" };
	size_t size = 9;
	printf("myl:%zu,", ft_strlcat(dest, src, size));
	printf("%s", dest);
	return 0;
}
*/