/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-i <ide-la-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:50 by ide-la-i          #+#    #+#             */
/*   Updated: 2023/01/10 12:33:47 by ide-la-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> // quitar
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
char	ft_putbnr(int n);
int		ft_intlen(int n);

#endif