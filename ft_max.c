/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:38:35 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/17 18:25:21 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

//coge dos numeros (a) y (b) y devuelve (a) si es mayor que (b)