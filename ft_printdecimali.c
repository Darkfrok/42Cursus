/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimali.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:28:00 by cquezada          #+#    #+#             */
/*   Updated: 2020/12/23 13:14:57 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	auxdecimali1(t_flags *flags, int *d, char **temp,
char **spaces, char **temp2)
{
	*d = ft_positivediff(flags->width, ft_strlen(*temp));
	*(spaces) = ft_calloc(*d, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(*(spaces), '0', *d);
	else
		ft_memset(*(spaces), ' ', *d);
	*(temp2) = ft_strjoin(*(spaces), *(temp));
}
void	auxdecimali2(t_flags *flags, int *d, char **temp,
char **spaces, char **s)
{
if (flags->has_precision == 1)
	{
		(*d) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			(*d)++;
		(*spaces) = ft_calloc((*d), sizeof(char));
		ft_memset((*spaces), '0', (*d));
		(*temp) = ft_strjoin((*spaces), (*s));
	}
	else
	{
		(*temp) = ft_calloc(ft_strlen((*s)), sizeof(char));
		ft_memcpy((*temp), (*s), ft_strlen((*s)));
		(*temp)[ft_strlen((*s))] = '\0';
	}
}
char	*sustituteminus(char *str)
{
	int pos;

	pos = 0;
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
	int		d;
	char	*s;
	char	*temp;
	char	*spaces;
	char	*temp2;

	d = va_arg(args, int);
	if (d == 0 && flags->has_precision == 1)
	{
		s = malloc(sizeof(char));
		s[0] = '\0';
	}
	else
		s = ft_itoa(d);
	temp = NULL;
	temp2 = NULL;
	auxdecimali2(flags, &d, &temp, &spaces, &s);
	sustituteminus(temp);
	if (flags->has_width == 1 && flags->has_left == 0)
		auxdecimali1(flags, &d, &temp, &spaces, &temp2);
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		d = ft_positivediff(flags->width, ft_strlen(temp));
		spaces = ft_calloc(d, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(spaces, ' ', d);
		else
			ft_memset(spaces, flags->has_zero == 1 ? '0' : ' ', d);
		temp2 = ft_strjoin(temp, spaces);
	}
	else
		temp2 = ft_strjoin("", temp);
	if (flags->has_zero == 1 && flags->has_width == 1 && temp2[0] == '0')
		sustituteminus(temp2);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
}
