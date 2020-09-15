/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 15:41:26 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/15 15:48:38 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
int		ft_precisionsort(int c)
{
	int precision;
	int cont;

	cont = 0;
	precision = (int)c;
	while(precision != 0)  
   {
		precision = precision/10;  
		cont++;
   }
   //if (precision = '-')
	//	cont++;
	return (cont);
}