/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:05:11 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/19 14:30:52 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	flags->u = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->u, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->u);
	else
		ft_memset(flags->spaces, ' ', flags->u);
	flags->spaces[flags->d] = '\0';
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	free(flags->spaces);
}

static void	auxdecimali2(t_flags *flags, char **temp, char **s)
{
	if (flags->has_precision == 1)
	{
		(flags->u) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			flags->u++;
		flags->spaces = ft_calloc((flags->u), sizeof(char));
		ft_memset(flags->spaces, '0', (flags->u));
		flags->spaces[flags->d] = '\0';
		free(flags->spaces);
		(*temp) = ft_strjoin(flags->spaces, (*s));
	}
	else
	{
		(*temp) = ft_calloc(ft_strlen((*s)), sizeof(char));
		ft_memcpy((*temp), (*s), ft_strlen((*s)));
		(*temp)[ft_strlen((*s))] = '\0';
	}
}

static void	auxdecimali3(t_flags *flags, char **temp, char **temp2)
{
	if (flags->has_width == 1 && flags->has_left == 0)
		auxdecimali1(flags, temp, temp2);
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		flags->u = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->u, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(flags->spaces, ' ', flags->u);
		else
		{
			ft_memset(flags->spaces,
			flags->has_zero == 1 ? '0' : ' ', flags->u);
		}
		flags->spaces[flags->d] = '\0';
		*(temp2) = ft_strjoin(*(temp), flags->spaces);
		free(flags->spaces);
	}
	else
		*(temp2) = ft_strjoin("", *(temp));
}

void		ft_printu(va_list args, t_flags *flags, int *pos)
{
	char	*s;
	char	*temp;
	char	*temp2;

	flags->u = va_arg(args, unsigned int);
	if (flags->u == 0 && flags->has_precision == 1)
	{
		s = malloc(sizeof(char));
		s[0] = '\0';
	}
	else
		s = ft_utoa(flags->u);
	temp = NULL;
	temp2 = NULL;
	auxdecimali2(flags, &temp, &s);
	sustituteminus(temp);
	auxdecimali3(flags, &temp, &temp2);
	if (flags->has_zero == 1 && flags->has_width == 1 && temp2[0] == '0')
		sustituteminus(temp2);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
	(*pos)++;
}
