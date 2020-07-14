/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:37:35 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:19 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			cont;

	str = (unsigned char *)s;
	cont = 0;
	while (cont < n)
	{
		if (str[cont] == (unsigned char)c)
			return ((void *)&str[cont]);
		cont++;
	}
	return (NULL);
}
