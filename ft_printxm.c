/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:03:22 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/24 11:29:51 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printxm(va_list args)
{
	char *xm;

	(void)xm;
	(void)args;
	ft_putstr_fd("Entero en base 16 con las letras en MAYUSCULAS", 1);
}
