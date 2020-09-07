/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:23:08 by cquezada          #+#    #+#             */
/*   Updated: 2020/08/11 11:51:58 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *puntero;

	puntero = malloc(count * size);
	if (puntero == NULL)
		return (puntero);
	ft_bzero(puntero, size * count);
	return (puntero);
}
