/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:54:51 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/17 11:08:40 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct	s_flags
{
	size_t			width;
	int				has_width;
	int 			has_precision;
	size_t			precision;
	int 			has_left;
	int 			left;
	int 			has_zero;
	int 			zero;
	size_t 			r_count;
	char 			*spaces;
	int				d;
	int				w;
	int				x;
	unsigned int	u;
	int				has_xmayus;
	int				has_hex;
}					t_flags;

int			ft_printf(const char *str, ...);
void		ft_printstr(va_list args, t_flags *flags, int *pos);
void		ft_printchar(va_list args, t_flags *flags, int *pos);
void		ft_printdecimali(va_list args, t_flags *flags, int *pos);
void		ft_printu(va_list args, t_flags *flags, int *pos);
void		ft_printxm(va_list args);
void		ft_printx(va_list args);
void		ft_printpointer(va_list args, t_flags *flags, int *pos);
void		resetflags(t_flags *flags);
void		printflags(t_flags flags);
void		ft_checkflags(va_list args, const char *str, t_flags *flags, int *pos);
int			ft_digitcount(int c);
size_t 		ft_min(size_t a, size_t b);
size_t 		ft_max(size_t a, size_t b);
int			ft_positivediff(int a, int b);
char 		*sustituteminus(char *str);
char		*ft_itohex(unsigned int decimalnum);
char		*ft_invertstr(char *str);
void		ft_printhex(va_list args, t_flags *flags, int *pos);
char 		*ft_strtoupper(char *temp);
void		putcharpercent(char *s, t_flags *flags, int *pos);
char    	*ft_longtohex(unsigned long decimalnum);
#endif
