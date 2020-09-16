/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/16 18:28:14 by cquezada         ###   ########.fr       */
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
	int contdsortp;
	t_flags	flags;

	pos = 0;
	cont = 0;
	contdsortp = 0;
	contdsort = 0;
	va_start(args, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			resetflags(&flags);
			cont++;
			pos++;
			ft_checkflags(str, &flags, &pos);
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
	ft_printf("Hola %48.3234s \n", "buenas");
	printf("Hola %3s \n", "buenas");
}
