/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 11:50:21 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/20 14:04:25 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	ft_printchar(va_list args, t_flags *flags)
{
	char	c;
	int	i;

	i = 0;
	c = va_arg(args, int);
	if ((flags->has_width == 1 && (flags->has_left == 0)))
	{
		while (i < (flags->width - 1))
		{
			ft_putchar_fd(' ', 1);
			i++;
			flags->r_count++;
		}
	}
	ft_putchar_fd(c, 1);
	flags->r_count++;
	if ((flags->has_width == 1) && (flags->has_left == 1))
		while (i < (flags->width - 1))
		{
			ft_putchar_fd(' ', 1);
			i++;
			flags->r_count++;
		}
}
