/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2020/06/29 11:20:59 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

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
		}
		ft_putchar(str[cont]);
		cont++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("Hello Worlds cspdiuxX % \n");
}
