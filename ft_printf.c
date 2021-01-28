/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2021/01/28 14:03:09 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	int pos;
	t_flags	flags;

	pos = 0;
	flags.r_count = 0;
	va_start(args, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			resetflags(&flags);
			pos++;
			ft_checkflags(str, &flags, &pos);
			//printflags(flags);
			if (str[pos] == '%')
			{
				ft_putchar_fd('%', 1);
				flags.r_count++;
				pos++;
			}
			else if (str[pos] == 's')
			{
				ft_printstr(args, &flags);
				pos++;
			}
			else if (str[pos] == 'c')
			{
				ft_printchar(args, &flags);
				pos++;
			}
			else if (str[pos] == ('d') || str[pos] == ('i'))
			{
				ft_printdecimali(args, &flags);
				pos++;
			}
			else if (str[pos] == 'u')
			{
				ft_printu(args);
				pos++;
			}
			else if (str[pos] == 'X')
			{
				ft_printxm(args);
				pos++;
			}
		}
		else
		{
			ft_putchar_fd(str[pos], 1);
			pos++;
			flags.r_count++;
		}
	}
	return (flags.r_count);
}

// int	main(void)
// {
// 	int t;
// 	int c;
// 	int cont;
// 	int cont2;

// 	t = 70;
// 	c = 60;
// 	  cont = ft_printf("%32s", "abc");
// 	printf("\nContador:    %i\n", cont);
// 		cont2 = printf("%32s", "abc");
// 	printf("\nContador 2:  %i\n", cont2);
// }
