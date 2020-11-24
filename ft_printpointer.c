/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/24 11:29:40 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_printpointer(va_list args)
{
	char *p;

	p = va_arg(args, char*);
	ft_putstr_fd("Esto imprime la direccion de memoria de un puntero", 1);
}
