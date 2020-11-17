/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:45:16 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/17 12:42:38 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widthsort(int c)
{
	int cont;

	cont = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c = c / 10;
		cont++;
	}
	return (cont);
}
