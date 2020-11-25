/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:04:17 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:22 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *fuente;
	char *destino;

	fuente = (char *)src;
	destino = (char *)dst;
	if (!dst && !src && len > 0)
		return (0);
	if (dst > src)
	{
		while (len--)
		{
			destino[len] = fuente[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
