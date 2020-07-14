/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:39:19 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:08 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int rato;
	int neg;
	int cont;

	cont = 0;
	neg = 1;
	rato = 0;
	while (str[cont] != '\0' && (str[cont] == ' ' || str[cont] == '\n' ||
	str[cont] == '\t' || str[cont] == '\v' || str[cont] == '\f' ||
	str[cont] == '\r'))
	{
		cont++;
	}
	if ((str[cont] == '-') || (str[cont] == '+'))
	{
		if (str[cont] == '-')
			neg = -1;
		cont++;
	}
	while (str[cont] != '\0' && str[cont] >= '0' && str[cont] <= '9')
	{
		rato = (rato * 10) + (str[cont] - '0');
		cont++;
	}
	return (rato * neg);
}
