/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:54:27 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/11 15:11:44 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resetflags(t_flags *flags)
{
	flags->tiene_width = 0;
	flags->width = 0;
	flags->tiene_precision = 0;
	flags->precision = 0;
}

void	printflags(t_flags flags)
{
	ft_putstr_fd("tiene_width: ", 1);
	ft_putnbr_fd(flags.tiene_width, 1);
	ft_putstr_fd("\nwidth: ", 1);
	ft_putnbr_fd(flags.width, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("dwidth: ", 1);
	ft_putnbr_fd(ft_widthsort(flags.width), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("tiene_precision: ", 1);
	ft_putnbr_fd(flags.tiene_precision, 1);
	ft_putstr_fd("\nprecision: ", 1);
	ft_putnbr_fd(flags.precision, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_checkflags(char *str, t_flags *flags)
{
	int pos;
	int num;
	int dwidth;

	num = 0;
	pos = 0;
	if (str[pos] == '-')
	{
		str++;
		if (1 == ft_isdigit(str[pos]))
		{
			num = 1;
			flags->width = ft_atoi(str);
		}
	}
	if (1 == ft_isdigit(str[pos]))
		{
			num = 1;
			flags->width = ft_atoi(str);
		}
	if (num == 1)
		flags->tiene_width = 1;
}