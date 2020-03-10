/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peraux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:12:32 by cquezada          #+#    #+#             */
/*   Updated: 2020/03/10 13:50:05 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	peraux(char *str)
{
	if (str == '%')
{
	str++;
	if (str == '%')
	{
		ft_putchar('%');
		str++;
	}
	if (str == 'c')
		ft_putchar('1');
	if (str == 's')
		ft_putchar('2');
	if (str == 'p')
		ft_putchar('3');
	if (str == 'd' || str == 'i')
		ft_putchar('4');
	if (str == 'u')
		ft_putchar('5');
	if (str == 'x')
		ft_putchar('6');
	if (str == 'X' || str == 'i')
		ft_putchar('7');
}
}
