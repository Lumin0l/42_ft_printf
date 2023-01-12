/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:54:36 by ide-la-i          #+#    #+#             */
/*   Updated: 2023/01/12 18:36:13 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_pointer(unsigned long int n)
{
	unsigned int	counter;

	counter = 1;
	if (n >= 16)
		counter = counter + ft_put_pointer(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	return (counter);
}

static int	ft_arg_processor(char c, va_list args)
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
	if (c == 'p')
	{
		ft_putstr("0x");
		return (counter = 2 + ft_put_pointer(va_arg(args, unsigned long int)));
	}
	else
		return (-1);
}	

int	ft_printf(char const *format_string, ...)
{
	unsigned int	i;
	int				counter;
	va_list			args;

	if (!format_string)
		return (-1);
	i = 0;
	counter = 0;
	va_start(args, format_string);
	while (format_string[i] != '\0')
	{
		if (format_string[i] != '%')
		{
			counter = counter + ft_putchar(format_string[i]);
			i++;
		}
		else
		{
			counter = counter + ft_arg_processor(format_string[i + 1], args);
			i = i + 2;
		}
	}
	va_end(args);
	return (counter);
}

/*
int	main(void)
{
	int num;
	char *pointer = "asdf";
	
	ft_printf("Test char1: ");
	num = ft_printf("%c\n", 'c');
	ft_printf("return value: %i\n\n", num);

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

	ft_printf("Test ponter1: ");
	num = ft_printf("%p\n", pointer);
	ft_printf("return value: %i\n\n", num);
	
	ft_printf("Test error1: ");
	num = ft_printf("%q\n", 10);
	ft_printf("return value: %i\n\n", num);
}
*/