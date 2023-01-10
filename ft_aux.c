/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:54 by ide-la-i          #+#    #+#             */
/*   Updated: 2023/01/10 15:50:02 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	unsigned int	counter;
	unsigned int	i;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		counter = counter + ft_putchar(str[i]);
		i++;
	}
	return (counter);
}

int	ft_putnbr(int n)
{
	unsigned int	num;
	unsigned int	counter;

	num = 0;
	counter = 1;
	if (n < 0)
	{
		num = n * -1;
		ft_putchar('-');
		counter++;
	}
	else
		num = n;
	if (num > 9)
	{
		counter = counter + ft_putnbr((num / 10));
	}
	ft_putchar((num % 10) + '0');
	return (counter);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	counter;

	counter = 1;
	if (n > 9)
	{
		counter = counter + ft_putnbr((n / 10));
	}
	ft_putchar((n % 10) + '0');
	return (counter);
}
