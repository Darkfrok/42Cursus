/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:05 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/24 11:29:26 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printx(va_list args)
{
	char *x;

	(void)x;
	(void)args;
	ft_putstr_fd("Un entero en base 16 con las letras en minuscula", 1);
}
