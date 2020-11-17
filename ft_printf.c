/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/17 13:17:06 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int pos;
	//int flags.r_countdsort;
	//int flags.r_countdsortp;
	t_flags	flags;

	pos = 0;
	flags.r_count = 0;
	//flags.r_countdsortp = 0;
	//flags.r_countdsort = 0;
	va_start(args, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%')
		{
			resetflags(&flags);
		//	flags.r_count++;
			pos++;
			ft_checkflags(str, &flags, &pos);
			if (str[pos] == '%')
			{
				ft_putchar('%');
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
				ft_printchar(args);
				flags.r_count++;
				pos++;
			}
			else if (str[pos] == ('d') || str[pos] == ('i'))
			{
				ft_printdecimali(args);
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
		//	printflags(flags);
		}
		else
		{
			ft_putchar(str[pos]);
			pos++;
			flags.r_count++;
		}
	}
	return (flags.r_count);
}

// int	main(void)
// {
// 	char t[] = "tardes";
// 	char *c;
// 	int cont;
// 	int cont2;

// 	c = "XUBUNTU";
// 	cont = ft_printf("%.03s", "hello");
// 	printf("\nContador : %i\n", cont);
// 	cont2 = printf("%.03s", "hello");
// 	printf("\nContador 2: %i\n", cont2);
// }
