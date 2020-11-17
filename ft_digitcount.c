/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:45:16 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/17 19:00:29 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digitcount(int c)
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
