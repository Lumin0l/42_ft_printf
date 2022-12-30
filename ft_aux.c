/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:54 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/30 15:34:03 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
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
