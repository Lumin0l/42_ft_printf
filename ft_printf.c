/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:37:30 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/30 15:53:51 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_processor(char *c, va_list args)
{
	unsigned int	counter;
	char			*to_print;
	
	if (c == 'c')
	{
		to_print = va_arg(args, char);
		counter = counter + ft_putchar(to_print);
	}
	if (c == 's')
	{
		to_print = va_arg(args, char *);
		counter = counter + ft_putstr(to_print);

	}
	if (c == 'i' || c == 'd' || c == 'u')
	{
		to_print = ft_itoa(va_arg(args, int));
		counter = counter + ft_putstr(to_print);
	}
	if (c == 'o')
	{
		
	}
	return (counter);
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