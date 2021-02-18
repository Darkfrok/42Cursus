/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharpercent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:45:32 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/18 12:04:11 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putcharpercent(t_flags *flags, int *pos)
{
	size_t	i;

	i = 0;
	if ((flags->has_width == 1 && (flags->has_left == 0)))
	{
		while (i < (flags->width - 1))
		{
			if (flags->has_zero == 1)
			{
				ft_putchar_fd('0', 1);
				i++;
				flags->r_count++;
			}
			else
			{
				ft_putchar_fd(' ', 1);
				i++;
				flags->r_count++;
			}
		}
	}
	ft_putchar_fd('%', 1);
	flags->r_count++;
	if ((flags->has_width == 1) && (flags->has_left == 1))
		while (i < (flags->width - 1))
		{
			ft_putchar_fd(' ', 1);
			i++;
			flags->r_count++;
		}
	(*pos)++;
}
