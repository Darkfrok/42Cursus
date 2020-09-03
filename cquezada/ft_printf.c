/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/03 12:38:29 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include "./ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int cont;

	cont = 0;
	va_start(args, str);
	while (str[cont] != '\0')
	{
		if (str[cont] == '%')
		{
			cont++;
			if (str[cont] == '%')
			{
				ft_putchar('%');
				cont++;
			}
			if (str[cont] == 's')
			{
				ft_printstr(args);
				str++;
			}
			if (str[cont] == 'c')
			{
				ft_printchar(args);
				str++;
			}
			if (str[cont] == ('d') || str[cont] == ('i'))
			{
				ft_printdecimali(args);
				str++;
			}
		}
		ft_putchar(str[cont]);
		cont++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("Hola %d \n", 1);
}
