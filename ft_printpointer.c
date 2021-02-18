/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/18 13:56:41 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	flags->d = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->d + 1, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->d);
	else
		ft_memset(flags->spaces, ' ', flags->d);
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	free(flags->spaces);
}

static void	auxdecimali2(t_flags *flags, char **temp, char **s)
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

static void	auxdecimali3(t_flags *flags, char **temp, char **temp2, int *pos)
{
	free(*temp2);
	if (flags->has_width == 1 && flags->has_left == 0)
	{
		ft_bzero(*(temp2), ft_strlen(*(temp2)));
		auxdecimali1(flags, temp, temp2);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		flags->d = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->d + 1, sizeof(char));
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
	(*pos)++;
}

void		ft_printpointer(va_list args, t_flags *flags, int *pos)
{
	char			*s;
	char			*temp;
	char			*temp2;
	unsigned long	d;

	temp = NULL;
	temp2 = NULL;
	d = va_arg(args, unsigned long);
	if (d == 0 && flags->has_precision == 1)
		s = ft_calloc(sizeof(char), 1);
	else if (d == 0)
	{
		s = ft_calloc(sizeof(char), 2);
		s[0] = '0';
	}
	else
		s = ft_longtohex(d);
	auxdecimali2(flags, &temp2, &s);
	temp = ft_strjoin("0x", temp2);
	auxdecimali3(flags, &temp, &temp2, pos);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
}
