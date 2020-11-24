/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:05:11 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/24 11:29:21 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu(va_list args)
{
	unsigned int u;

	u = va_arg(args, unsigned int);
	ft_putnbr_fd(u, 1);
}
