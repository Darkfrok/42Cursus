/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:38:45 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:17 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				count;
	const unsigned char *source;
	unsigned char		*destiny;

	count = 0;
	source = (const unsigned char *)src;
	destiny = (unsigned char *)dst;
	if (!source && !destiny)
		return (0);
	while (count < n)
	{
		destiny[count] = source[count];
		if (destiny[count] == (unsigned char)c)
			return ((void*)(destiny + count + 1));
		count++;
	}
	return (0);
}
