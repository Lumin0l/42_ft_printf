/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:54:36 by ide-la-i          #+#    #+#             */
/*   Updated: 2023/01/11 11:02:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
casos:


p






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
	if (c == 'x' || c == 'X')
		return (counter = ft_puthexa(c, va_arg(args, int)));
/* Continuar aquí */
	if (c == 'p')
		return (counter = );
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
	
	ft_printf("Test char1: ");
	num = ft_printf("%c\n", 'c');
	ft_printf("return value:%i\n\n", num);

	ft_printf("Test char2:");
	num = ft_printf(" %c, %c, %c\n", 'a', 'b', 'c');
	ft_printf("return value: %i\n\n", num);

	ft_printf("Test hexa1: ");
	num = ft_printf("%x\n", 41394);
	ft_printf("return value: %i\n\n", num);

	ft_printf("Test hexa2: ");
	num = ft_printf("%X\n", 41394);
	ft_printf("return value: %i\n\n", num);

	ft_printf("Test hexa3: ");
	num = ft_printf("%x, %X, %x, %X\n", 41394, 50132, 50132, 41394);
	ft_printf("return value: %i\n\n", num);
	

	num = printf("%%\n");
	printf("%i\n", num);
}