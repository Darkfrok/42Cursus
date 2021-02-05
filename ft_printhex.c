/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:48:26 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/05 12:58:06 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void	auxhex1(t_flags *flags, char **temp, char **temp2)
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

void	auxhex2(t_flags *flags, char **temp, char **s)
{
	if (flags->has_precision == 1)
	{
		(flags->d) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			flags->d++;
		flags->spaces = ft_calloc((flags->d), sizeof(char));
		ft_memset(flags->spaces, '0', (flags->d));
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

void	auxhex3(t_flags *flags, char **temp, char **temp2)
{
	if (flags->has_width == 1 && flags->has_left == 0)
		auxhex1(flags, temp, temp2);
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

void	ft_printhex(va_list args, t_flags *flags)
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
		s = ft_itohex(flags->d);
    temp = NULL;
	temp2 = NULL;
	auxhex2(flags, &temp, &s);
	sustituteminus(temp);
	auxhex3(flags, &temp, &temp2);
	if (flags->has_zero == 1 && flags->has_width == 1 && temp2[0] == '0')
		sustituteminus(temp2);
    if(flags->has_xmayus == 1)
        ft_strtoupper(ft_itohex(flags->d));
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
}
