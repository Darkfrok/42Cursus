/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:45:16 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/16 18:33:17 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
int		ft_widthsort(int c)
{
	int width;
	int cont;

	cont = 0;
	width = (int)c;
	while(width != 0)
	{
		width = width/10;
		cont++;
   	}
	return (cont);
}