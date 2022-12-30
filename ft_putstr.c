/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:14:22 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/30 13:49:15 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
