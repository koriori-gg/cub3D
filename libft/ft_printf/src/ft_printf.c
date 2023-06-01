/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:22:56 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/10 11:39:56 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_check_format(const char *format, int i, va_list *args)
{
	if (format[i] == 'c')
		return (ft_putchar_std(va_arg(*args, int)));
	else if (format[i] == 's')
		return (ft_putstr_std(va_arg(*args, char *)));
	else if (format[i] == 'p')
		return (ft_putvoid_std(va_arg(*args, void *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr_std(va_arg(*args, int)));
	else if (format[i] == 'u')
		return (ft_utoa((unsigned long)va_arg(*args, unsigned int),
				10, "0123456789"));
	else if (format[i] == 'x')
		return (ft_utoa((unsigned long)va_arg(*args, unsigned int),
				16, "0123456789abcdef"));
	else if (format[i] == 'X')
		return (ft_utoa((unsigned long)va_arg(*args, unsigned int),
				16, "0123456789ABCDEF"));
	else if (format[i] == '%')
		return (ft_putchar_std(format[i]));
	else
		return (ft_putchar_std(format[i]));
}

int	ft_printf(const char *format, ...)
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
			check = ft_check_format(format, ++i, &args);
		else
			check = ft_putchar_std(format[i]);
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
	char s = "abc";
	int i = ft_printf("%c %s %p %d %i %x %X\n",
	'a', "abcd", s, 2147483647, 2147483647, 2147483647);
	int j = printf("%c %s %p %d %i %x %X\n",
	'a', "abcd", s, 2147483647, 2147483647, 2147483647);
	printf("i:%d,j:%d\n",i,j);
	ft_printf("%234");
}*/