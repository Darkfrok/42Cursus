/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:59:15 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/16 18:54:19 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_putcharsp_fd(char c, int fd, int *pos, t_flags *flags)
{
	write(fd, &c, 1);
	(*pos)++;
	flags->r_count++;
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			pos;
	t_flags		flags;

	pos = 0;
	flags.r_count = 0;
	va_start(args, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == '%' && str[pos + 1] != '\0')
		{
			resetflags(&flags);
			pos++;
			ft_checkflags(str, &flags, &pos);
			if (str[pos] == '%')
				putcharpercent("%", &flags, &pos);
			else if (str[pos] == 's')
				ft_printstr(args, &flags, &pos);
			else if (str[pos] == 'c')
				ft_printchar(args, &flags, &pos);
			else if (str[pos] == 'd' || str[pos] == 'i')
				ft_printdecimali(args, &flags, &pos);
			else if (str[pos] == 'u')
				ft_printu(args, &flags, &pos);
			else if (str[pos] == 'X' || str[pos] == 'x')
				ft_printhex(args, &flags, &pos);
			else if (str[pos] == 'p')
				ft_printpointer(args, &flags, &pos);
			else if (str[pos] == '*')
				ft_putchar_fd('*', 1);
		}
		else
			ft_putcharsp_fd(str[pos], 1, &pos, &flags);
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
// 	cont = ft_printf("p: %p", 450);
// 	printf("\nContador:    %i\n", cont);
// 	cont2 = printf("p: %p", 450);
// 	printf("\nContador 2:  %i\n", cont2);
// 	//system("leaks a.out");
// }
