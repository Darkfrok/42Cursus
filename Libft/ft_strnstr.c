/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:00:44 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:55:01 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int cont;
	unsigned int posicion;

	if (!*needle)
		return ((char*)haystack);
	posicion = 0;
	while (haystack[posicion] != '\0' && (size_t)posicion < len)
	{
		if (haystack[posicion] == needle[0])
		{
			cont = 1;
			while (needle[cont] != '\0' &&
			haystack[posicion + cont] == needle[cont] &&
					(size_t)(posicion + cont) < len)
				++cont;
			if (needle[cont] == '\0')
				return ((char*)&haystack[posicion]);
		}
		++posicion;
	}
	return (0);
}
