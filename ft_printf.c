/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:54:36 by ide-la-i          #+#    #+#             */
/*   Updated: 2023/01/10 16:01:57 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
casos:


p



x
X

*/
int	ft_arg_processor(char c, va_list args)
{
	unsigned int	counter;

	if (c == '%')
		counter = ft_putchar('%');
	if (c == 'c')
		return (counter = ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (counter = ft_putstr(va_arg(args, char *)));
	if (c == 'i' || c == 'd')
		return (counter = ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (counter = ft_putnbr_unsigned(va_arg(args, unsigned int)));
/* Continuar aquí */
	if (c == 'p')
		return (counter = counter + ft_putstr(va_arg(args, void *)));
}		

int	ft_printf(char const *format_string, ...)
{
	char			*str;
	unsigned int	i;
	unsigned int	counter;
	va_list			args;

	if (!format_string)
		return (-1);
	i = 0;
	counter = 0;
	str = (char *)format_string;
	va_start(args, format_string);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			counter = counter + ft_putchar(str[i]);
			i++;
		}
		else
		{
			counter = counter + ft_arg_processor(str[i + 1], args);
			i = i + 2;
		}
	}
	va_end(args);
	return (counter);
}

int	main(void)
{
	int num;
	
	num = ft_printf("%s\n", "cinco");
	printf("%i\n\n", num);
	

	num = printf("%%\n");
	printf("%i\n", num);
}