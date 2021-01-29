/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimali.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:28:00 by cquezada          #+#    #+#             */
/*   Updated: 2021/01/29 13:46:33 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	flags->d = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->d, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->d);
	else
		ft_memset(flags->spaces, ' ', flags->d);
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	free(flags->spaces);
}

void	auxdecimali2(t_flags *flags, char **temp, char **s)
{
	if (flags->has_precision == 1)
	{
		(flags->d) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			flags->d++;
		flags->spaces = ft_calloc((flags->d), sizeof(char));
		ft_memset(flags->spaces, '0', (flags->d));
		(*temp) = ft_strjoin(flags->spaces, (*s));
		free(flags->spaces);
	}
	else
	{
		(*temp) = ft_calloc(ft_strlen((*s)), sizeof(char));
		ft_memcpy((*temp), (*s), ft_strlen((*s)));
		(*temp)[ft_strlen((*s))] = '\0';
	}
}

void	auxdecimali3(t_flags *flags, char **temp, char **temp2)
{
	if (flags->has_width == 1 && flags->has_left == 0)
		auxdecimali1(flags, temp, temp2);
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		flags->d = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->d, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(flags->spaces, ' ', flags->d);
		else
		{
			ft_memset(flags->spaces,
			flags->has_zero == 1 ? '0' : ' ', flags->d);
		}
		*(temp2) = ft_strjoin(*(temp), flags->spaces);
		free(flags->spaces);
	}
	else
		*(temp2) = ft_strjoin("", *(temp));
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
	char	*s;
	char	*temp;
	char	*temp2;

	flags->d = va_arg(args, int);
	if (flags->d == 0 && flags->has_precision == 1)
	{
		s = malloc(sizeof(char));
		s[0] = '\0';
	}
	else
		s = ft_itoa(flags->d);
	temp = NULL;
	temp2 = NULL;
	auxdecimali2(flags, &temp, &s);
	sustituteminus(temp);
	auxdecimali3(flags, &temp, &temp2);
	if (flags->has_zero == 1 && flags->has_width == 1 && temp2[0] == '0')
		sustituteminus(temp2);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(s);
	free(temp);
	free(temp2);
}
