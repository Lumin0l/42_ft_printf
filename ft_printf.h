/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:50 by ide-la-i          #+#    #+#             */
/*   Updated: 2022/12/30 15:32:16 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> // quitar
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
int		ft_putchar(char c);
int		ft_putchar(char c);
char	*ft_itoa(int n);

#endif