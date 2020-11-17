/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:54:51 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/16 20:17:34 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_flags
{
	int	width;
	int	tiene_width;
	int tiene_precision;
	size_t	precision;
	int tiene_left;
	int left;
	int tiene_zero;
	int zero;
	size_t r_count;
	int if_null;
}				t_flags;

int			ft_printf(const char *str, ...);
void		ft_printstr(va_list args, t_flags *flags);
void		ft_printchar(va_list args);
void		ft_printdecimali(va_list args);
void		ft_printu(va_list args);
void		ft_printxm(va_list args);
void		ft_printx(va_list args);
void		ft_printpointer(va_list args);
void		resetflags(t_flags *flags);
void		printflags(t_flags flags);
void		ft_checkflags(const char *str, t_flags *flags, int *pos);
int			ft_widthsort(int c);
size_t 		ft_min(size_t a, size_t b);
size_t 		ft_max(size_t a, size_t b);
int			ft_ifminus (int a, int b);
#endif
