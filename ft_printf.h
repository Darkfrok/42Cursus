/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:54:51 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/04 13:26:01 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./Libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_printstr(va_list args);
void	ft_printchar(va_list args);
void	ft_printdecimali(va_list args);
void	ft_printu(va_list args);
void	ft_printxm(va_list args);
void	ft_printx(va_list args);
void	ft_printpointer(va_list args);
#endif