/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:25:12 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/30 15:33:42 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_intlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
	len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_populate(long int num, long int len, char *string)
{
	if (num < 0)
	{
		num *= -1;
		string[0] = '-';
	}
	if (num == 0)
	{
		string[0] = '0';
		return (string);
	}
	while (num > 0)
	{
		string[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char			*string;
	long int		num;
	long int		len;

	len = ft_intlen(n);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[len] = '\0';
	len--;
	num = n;
	return (ft_populate(num, len, string));
}
