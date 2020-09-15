/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/15 16:03:00 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include "./ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int cont;
	int pos;
	int contdsort;
	t_flags	flags;

	pos = 0;
	cont = 0;
	contdsort = 0;
	va_start(args, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			resetflags(&flags);
			cont++;
			pos++;
			ft_checkflags(&str[pos], &flags);
			//if (ft_isdigit(str[pos]) == 1)
				//contdsort = ft_widthsort(flags.width);
			if (str[pos] == '.')
			{
				pos++;
				contdsort = ft_precisionsort(flags.precision);
			}
			if (str[pos] == '-')
				contdsort++;
			if (flags.tiene_width || flags.tiene_precision == 1)
			{
				//ft_putchar_fd('\n', 1);
				//ft_putnbr_fd(contdsort, 1);
				while (contdsort != 0)
				{
					pos++;
					contdsort--;
				}
				
			}
			if (str[pos] == '%')
			{
				ft_putchar('%');
				cont++;
				pos++;
			}
			if (str[pos] == 's')
			{
				ft_printstr(args);
				pos++;
			}
			if (str[pos] == 'c')
			{
				ft_printchar(args);
				pos++;
				cont++;
			}
			if (str[pos] == ('d') || str[pos] == ('i'))
			{
				ft_printdecimali(args);
				pos++;
			}
			if (str[pos] == 'u')
			{
				ft_printu(args);
				pos++;
			}
			if (str[pos] == 'X')
			{
				ft_printxm(args);
				pos++;
			}
		}
		ft_putchar(str[pos]);
		pos++;
		cont++;
	}
	printflags(flags);
	return (0);
}

int	main(void)
{

	ft_printf("Hola %.33s \n", "buenas");
	printf("Hola %3s \n", "buenas");

}
