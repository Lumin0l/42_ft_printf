/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:37:30 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/22 16:10:19 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <varargs.h>

int	ft_printf(char const *format_string, ...)
{
	/* Declare variables to use */
	char 			*str;
	unsigned int	i;
	/* Declare special arguments */
	va_list 		args;

	/* Initialize special arguments */
	i = 0;
	str = format_string;
	va_start(args, format_string);

	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		else
			ft_ars_factory(str[i + 1]);
	}
	
}