/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimali.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:28:00 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/24 11:29:32 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdecimali(va_list args)
{
	char d;

	d = va_arg(args, int);
	ft_putnbr_fd(d, 1);
}
