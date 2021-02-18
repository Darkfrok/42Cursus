/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharpercent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:45:32 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/18 13:42:59 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxpercent(t_flags *flags)
{
	flags->i = 0;
	if ((flags->has_width == 1 && (flags->has_left == 0)))
	{
		while (flags->i < (flags->width - 1))
		{
			if (flags->has_zero == 1)
			{
				ft_putchar_fd('0', 1);
				flags->i++;
				flags->r_count++;
			}
			else
			{
				ft_putchar_fd(' ', 1);
				flags->i++;
				flags->r_count++;
			}
		}
	}
}

void		putcharpercent(t_flags *flags, int *pos)
{
	auxpercent(flags);
	ft_putchar_fd('%', 1);
	flags->r_count++;
	if ((flags->has_width == 1) && (flags->has_left == 1))
		while (flags->i < (flags->width - 1))
		{
			ft_putchar_fd(' ', 1);
			flags->i++;
			flags->r_count++;
		}
	(*pos)++;
}
