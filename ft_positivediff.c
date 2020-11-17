/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positivediff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:48:43 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/17 19:04:11 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_positivediff(int a, int b)
{
	int c;

	c = (a - b);
	if (c < 0)
		return (0);
	else
		return (c);
}


//Coge dos numeros y los resta, si el numero resultado es negativo devuelve 0 si es positivo devuelve el mismo




//una funcion que reciba 2 numeros, y reste el primero menos el segundo
//if el numero resultado es negativo, devuelve cero