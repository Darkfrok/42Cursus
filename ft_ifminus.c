/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifminus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:48:43 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/16 11:27:57 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ifminus(int a, int b)
{
	int c;

	c = (a - b);
	if (c < 0)
		return (0);
	else
		return (c);
}







//una funcion que reciba 2 numeros, y reste el primero menos el segundo
//if el numero resultado es negativo, devuelve cero