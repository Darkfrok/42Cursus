/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:26:03 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/19 13:29:43 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_flags
{
	size_t			width;
	int				has_width;
	int				has_precision;
	size_t			precision;
	int				has_left;
	int				left;
	int				has_zero;
	int				zero;
	size_t			r_count;
	char			*spaces;
	int				d;
	int				w;
	int				x;
	unsigned int	u;
	int				has_xmayus;
	int				has_hex;
	size_t			i;
}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_printstr(va_list args, t_flags *flags, int *pos);
void			ft_printchar(va_list args, t_flags *flags, int *pos);
void			ft_printdecimali(va_list args, t_flags *flags, int *pos);
void			ft_printu(va_list args, t_flags *flags, int *pos);
void			ft_printpointer(va_list args, t_flags *flags, int *pos);
void			resetflags(t_flags *flags);
void			printflags(t_flags flags);
void			ft_checkflags(va_list args, const char *str, t_flags *flags,
				int *pos);
size_t			ft_min(size_t a, size_t b);
int				ft_positivediff(int a, int b);
char			*sustituteminus(char *str);
char			*ft_itohex(unsigned int decimalnum);
char			*ft_invertstr(char *str);
void			ft_printhex(va_list args, t_flags *flags, int *pos);
char			*ft_strtoupper(char *temp);
void			putcharpercent(t_flags *flags, int *pos);
char			*ft_longtohex(unsigned long decimalnum);

#endif
