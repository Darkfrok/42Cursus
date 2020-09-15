/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:54:51 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/15 15:43:16 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./Libft/libft.h"
# include <stdarg.h>
typedef	struct	s_flags
{
	int	width;
	int	tiene_width;
	int tiene_precision;
	int precision;
}				t_flags;

int		ft_printf(const char *str, ...);
void	ft_printstr(va_list args);
void	ft_printchar(va_list args);
void	ft_printdecimali(va_list args);
void	ft_printu(va_list args);
void	ft_printxm(va_list args);
void	ft_printx(va_list args);
void	ft_printpointer(va_list args);
void	resetflags(t_flags *flags);
void	printflags(t_flags flags);
void	ft_checkflags(char *str, t_flags *flags);
int		ft_widthsort(int c);
int		ft_precisionsort(int c);
#endif