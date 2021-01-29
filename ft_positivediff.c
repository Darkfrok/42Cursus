/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positivediff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:48:43 by cquezada          #+#    #+#             */
/*   Updated: 2021/01/29 12:29:10 by cquezada         ###   ########.fr       */
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
