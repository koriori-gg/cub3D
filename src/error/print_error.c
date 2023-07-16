/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <ihashimo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:33:32 by ihashimo          #+#    #+#             */
/*   Updated: 2023/07/16 13:24:53 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

ssize_t	check_format_err(const char *format, int i, va_list *args)
{
	if (format[i] == 'c')
		return (ft_putchar_stderr(va_arg(*args, int)));
	else if (format[i] == 's')
		return (ft_putstr_stderr(va_arg(*args, char *)));
	else if (format[i] == 'p')
		return (ft_putvoid_stderr(va_arg(*args, void *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr_stderr(va_arg(*args, int)));
	else if (format[i] == 'u')
		return (utoa_stderr((unsigned long)va_arg(*args, unsigned int),
				10, "0123456789"));
	else if (format[i] == 'x')
		return (utoa_stderr((unsigned long)va_arg(*args, unsigned int),
				16, "0123456789abcdef"));
	else if (format[i] == 'X')
		return (utoa_stderr((unsigned long)va_arg(*args, unsigned int),
				16, "0123456789ABCDEF"));
	else if (format[i] == '%')
		return (ft_putchar_stderr(format[i]));
	else
		return (ft_putchar_stderr(format[i]));
}

int	print_error(const char *format, ...)
{
	ssize_t	i;
	ssize_t	count;
	ssize_t	check;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			check = check_format_err(format, ++i, &args);
		else
			check = ft_putchar_stderr(format[i]);
		if (check == -1)
			return (-1);
		count += check;
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	char *s = "abc";
	int i = print_error("%c %s %p %d %i %x %X\n",
	'a', "abcd", s, 2147483647, 2147483647, 2147483647, 2147483647);
	int j = printf("%c %s %p %d %i %x %X\n",
	'a', "abcd", s, 2147483647, 2147483647, 2147483647, 2147483647);
	printf("i:%d,j:%d\n",i,j);
	print_error("%234");
}
*/