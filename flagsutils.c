/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:54:27 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/09 06:15:54 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resetflags(t_flags *flags)
{
	flags->tiene_width = 0;
	flags->width = 0;
}

void	printflags(t_flags flags)
{
	ft_putstr_fd("tiene_width: ", 1);
	ft_putnbr_fd(flags.tiene_width, 1);
	ft_putstr_fd("\nwidth: ", 1);
	ft_putnbr_fd(flags.width, 1);
	ft_putchar_fd('\n', 1);
}
int		ft_checkflags(char *str, t_flags *flags)
{
	int pos;

	pos = 0;
	if(str[pos] )
}