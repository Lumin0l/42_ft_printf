/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:54 by ide-la-i          #+#    #+#             */
/*   Updated: 2023/01/10 12:33:23 by ide-la-i         ###   ########.fr       */
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
void	ft_putnbr(int n)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		num = n * -1;
		ft_putchar('-');
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr((num / 10));
	}
	ft_putchar((num % 10) + '0');
}
int	ft_intlen(int n)
{
	unsigned int	len;

	len = 0;
	ft_putnbr(n);
	if (n <= 0)
	len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}