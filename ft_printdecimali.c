/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimali.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:28:00 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/24 11:29:32 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdecimali(va_list args, t_flags *flags)
{
	int d;
	char *s;
	char *temp;
	char *temp2;
	char *spaces;
	int w;

	d = va_arg(args, int);
	s = ft_itoa(d);
	if ((flags->precision < ft_strlen(s)) && flags->has_precision == 1)
	{
		temp = ft_calloc((ft_min(flags->precision, ft_strlen(s)) + 1),
		sizeof(char));
		ft_memcpy(temp, s, flags->precision);
	}
	else
	{
		temp = ft_calloc(ft_strlen(s), sizeof(char));
		ft_memcpy(temp, s, ft_strlen(s));
		temp[ft_strlen(s)] = '\0';
	}
	if (flags->has_width == 1 && flags->has_left == 0)
	{		
		w = ft_positivediff(flags->width, ft_strlen(temp));
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, flags->has_zero == 1 ? '0' : ' ', w);
		temp2 = ft_strjoin(spaces, temp);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		w = ft_positivediff(flags->width, ft_strlen(temp));
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, ' ', w);
		temp2 = ft_strjoin(temp, spaces);
	}
	else
		temp2 = ft_strjoin("", temp);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
}

