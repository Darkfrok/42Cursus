/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimali.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:28:00 by cquezada          #+#    #+#             */
/*   Updated: 2020/12/22 18:51:05 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *sustituteminus(char *str)
{
int		pos;

pos = 0 ;
while (str[pos] != '\0')
{
	if (str[pos] == '-')
	{
		str[pos] = '0';
		str[0] = '-';
	}
	pos++;
}
return (str);
}

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
	
	if (flags->has_precision == 1)
	{
		w = ft_positivediff(flags->precision, ft_strlen(s));
		if (d < 0 && flags->precision > ft_strlen(s))
			w++;
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, '0', w);
		temp = ft_strjoin(spaces, s);
		if (flags->precision < flags->width)
			sustituteminus(temp);
		printf("\n1Temp: %s\n", temp);
	}
	else
	{
		temp = ft_calloc(ft_strlen(s), sizeof(char));
		ft_memcpy(temp, s, ft_strlen(s));
		temp[ft_strlen(s)] = '\0';
		printf("\n2Temp: %s\n", temp);
	}
		sustituteminus(temp);
		//printf("Temp: %s\n",temp);
		printf("\n3Temp: %s\n", temp);
	if (flags->has_width == 1 && flags->has_left == 0)
	{		
		w = ft_positivediff(flags->width, ft_strlen(temp));
		spaces = ft_calloc(w, sizeof(char));
		if (flags->precision <= flags->width)
//Has invertido la el orden de espacios y ceros, acuerdate.
			ft_memset(spaces, flags->has_zero == 1 ? '0': ' ', w);
		else
			ft_memset(spaces, flags->has_zero == 1 ? ' ' : '0', w);
		temp2 = ft_strjoin(spaces, temp);
		printf("\n4Temp: %s\n", temp);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		w = ft_positivediff(flags->width, ft_strlen(temp));
		printf("\n5Temp: %s\n", temp);
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, flags->has_zero == 1 ? '0' : ' ', w);
		temp2 = ft_strjoin(temp, spaces);
	}
	else
		temp2 = ft_strjoin("", temp);
	printf("\n6Temp: %s\n", temp2);
	if (flags->has_zero == 1)
		sustituteminus(temp2);
	printf("\n7Temp: %s\n", temp2);
	ft_putstr_fd(temp2, 1);
	printf("\n8Temp: %s\n", temp2);
	(flags->r_count) += ft_strlen(temp2);
	printf("\n9Temp: %s\n", temp2);
	free(temp);
	free(temp2);
}

