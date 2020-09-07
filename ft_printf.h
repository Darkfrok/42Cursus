/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkfrok <darkfrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:54:51 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/07 11:05:54 by darkfrok         ###   ########.fr       */
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
}				t_flags;

int		ft_printf(const char *str, ...);
void	ft_printstr(va_list args);
void	ft_printchar(va_list args);
void	ft_printdecimali(va_list args);
void	ft_printu(va_list args);
void	ft_printxm(va_list args);
void	ft_printx(va_list args);
void	ft_printpointer(va_list args);
#endif