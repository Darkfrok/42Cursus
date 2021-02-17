/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:54:27 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/17 19:15:08 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resetflags(t_flags *flags)
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

void	printflags(t_flags flags)	
{	
	ft_putstr_fd("\nhas_width: ", 1);	
	ft_putnbr_fd(flags.has_width, 1);	
	ft_putstr_fd("\nwidth: ", 1);	
	ft_putnbr_fd(flags.width, 1);	
	ft_putchar_fd('\n', 1);	
	ft_putstr_fd("dwidth: ", 1);	
	ft_putnbr_fd(ft_digitcount(flags.width), 1);	
	ft_putchar_fd('\n', 1);	
	ft_putstr_fd("dprecision: ", 1);	
	ft_putnbr_fd(ft_digitcount(flags.precision), 1);	
	ft_putchar_fd('\n', 1);	
	ft_putstr_fd("has_precision: ", 1);	
	ft_putnbr_fd(flags.has_precision, 1);	
	ft_putstr_fd("\nprecision: ", 1);	
	ft_putnbr_fd(flags.precision, 1);	
	ft_putchar_fd('\n', 1);	
	ft_putstr_fd("has_left: ", 1);	
	ft_putnbr_fd(flags.has_left, 1);	
	ft_putchar_fd('\n', 1);	
	ft_putstr_fd("has_zero: ", 1);	
	ft_putnbr_fd(flags.has_zero, 1);	
	ft_putstr_fd("\nzero: ", 1);	
	ft_putnbr_fd(flags.zero, 1);	
	ft_putstr_fd("\nhas_hex: ", 1);	
	ft_putnbr_fd(flags.has_hex, 1);	
	ft_putstr_fd("\nhas_xmayus: ", 1);	
	ft_putnbr_fd(flags.has_xmayus, 1);	
	ft_putchar_fd('\n', 1);	
	ft_putstr_fd("\nValor de retorno: ", 1);	
	ft_putnbr_fd(flags.r_count, 1);	
	ft_putchar_fd('\n', 1);	
}

void	ft_checkflags(va_list args, const char *str, t_flags *flags, int *pos)
{
	int	temp;
	while (str[*pos] == '0' || str[*pos] == '-')
	{
		str[*pos] == '-' ? flags->has_left = 1 : 1;
		str[*pos] == '0' ? flags->has_zero = 1 : 1;
		(*pos)++;
	}
	if (str[*pos] == '*')
	{
		flags->has_width = 1;
		temp = 0;
		temp = va_arg(args, int);
		//printf("temp %di\n", temp);
		if (temp < 0)
		{
			flags->has_left = 1;
			flags->width = -temp;
		}
		else
		{
			flags->width = temp;
			//printf("temp %di\n", temp);
		}
		(*pos)++;
	}
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
		if (str[*pos] == '*')
		{
			temp = 0;
			temp = va_arg(args, int);
			//printf("%i\n", temp);
			if (temp < 0)
			{
				flags->has_precision = 0;
				//printf("Hola")
				//flags->has_left = 1;
				// if (flags->)
				// {
				temp = 0;
				flags->precision =  temp;
				// }
			//	printf("precion:%i\n", flags->precision);
			}
			else
				flags->precision =  temp;
			
			// flags->precision = va_arg(args, int);
			(*pos)++;
		}
		else
		{
			flags->has_precision = 1;
			flags->precision = ft_atoi(&str[*pos]);
		}
		while (str[*pos] != 's' && str[*pos] != '.' && str[*pos] !=
		'c' && str[*pos] != 'd' && str[*pos] != 'i' && str[*pos] !=
		'x' && str[*pos] != 'X' && str[*pos] != 'u' && str[*pos] !=
		'p' && str[*pos] != '%')
			(*pos)++;
	}
	if (str[*pos] == 'x' || str[*pos] == 'X')
		str[*pos] == 'X' ? flags->has_xmayus = 1 : 1;
}
