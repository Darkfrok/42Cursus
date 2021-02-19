/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:54:27 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/19 14:04:44 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		resetflags(t_flags *flags)
{
	flags->has_width = 0;
	flags->width = 0;
	flags->has_precision = 0;
	flags->precision = 0;
	flags->has_left = 0;
	flags->has_zero = 0;
	flags->zero = 0;
	flags->has_hex = 0;
	flags->has_xmayus = 0;
	flags->left = 0;
}

static void	auxif1(va_list args, const char *str, t_flags *flags, int *pos)
{
	int temp;

	temp = 0;
	if (str[*pos] == '.')
	{
		flags->has_precision = 1;
		(*pos)++;
	}
	if (str[*pos] == '*')
	{
		temp = va_arg(args, int);
		if (temp < 0)
		{
			flags->has_precision = 0;
			flags->precision = 0;
		}
		else
			flags->precision = temp;
		(*pos)++;
	}
	else
	{
		flags->has_precision = 1;
		flags->precision = ft_atoi(&str[*pos]);
	}
}

static void	auxif2(va_list args, const char *str, t_flags *flags, int *pos)
{
	if (ft_isdigit(str[*pos]) == 1)
	{
		flags->has_width = 1;
		flags->width = ft_atoi(&str[*pos]);
		while (str[*pos] != 's' && str[*pos] != '.' && str[*pos] !=
		'c' && str[*pos] != 'd' && str[*pos] != 'i' && str[*pos] !=
		'x' && str[*pos] != 'X' && str[*pos] != 'u' && str[*pos] !=
		'p' && str[*pos] != '%')
			(*pos)++;
	}
	if (str[*pos] == '.')
	{
		flags->has_precision = 1;
		(*pos)++;
		auxif1(args, str, flags, pos);
		while (str[*pos] != 's' && str[*pos] != '.' && str[*pos] !=
		'c' && str[*pos] != 'd' && str[*pos] != 'i' && str[*pos] !=
		'x' && str[*pos] != 'X' && str[*pos] != 'u' && str[*pos] !=
		'p' && str[*pos] != '%')
			(*pos)++;
	}
	if (str[*pos] == 'x' || str[*pos] == 'X')
		str[*pos] == 'X' ? flags->has_xmayus = 1 : 1;
}

void		ft_checkflags(va_list args, const char *str, t_flags *flags,
			int *pos)
{
	int temp;

	temp = 0;
	while (str[*pos] == '0' || str[*pos] == '-')
	{
		str[*pos] == '-' ? flags->has_left = 1 : 1;
		str[*pos] == '0' ? flags->has_zero = 1 : 1;
		(*pos)++;
	}
	if (str[*pos] == '*')
	{
		flags->has_width = 1;
		temp = va_arg(args, int);
		if (temp < 0)
		{
			flags->has_left = 1;
			flags->width = -temp;
		}
		else
			flags->width = temp;
		(*pos)++;
	}
	auxif2(args, str, flags, pos);
}
