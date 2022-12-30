/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_V2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:54:36 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/30 16:22:46 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
casos:


p



x
X
%
*/
int	ft_arg_processor(char *c, va_list args)
{
	unsigned int	counter;
	
	if (c == 'c')
		return (counter = counter + ft_putchar(va_arg(args, char)));
	if (c == 's')
		return (counter = counter + ft_putstr(va_arg(args, char *)));
	if (c == 'i' || c == 'd' || c == 'u')
		return (counter = counter + ft_putstr(va_arg(args, int)));
	if (c == 'p')
		return (counter = counter + ft_putstr(va_arg(args, void *)));
}		

int	ft_printf(char const *format_string, ...)
{
	char 			*str;
	unsigned int	i;
	unsigned int	counter;
	va_list 		args;

	if (!format_string)
		return (-1);

	i = 0;
	counter = 0;
	str = format_string;
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
			if (str[i + 1] == '%')
				counter = counter + ft_putchar('%');
			else
				counter = counter + ft_arg_processor(str[i + 1], args);
			i++;
		}
	}
	va_end(args);
	return (counter + i);
}

int	main(void)
{
	int num;
	
	num = ft_printf("asdf");
}