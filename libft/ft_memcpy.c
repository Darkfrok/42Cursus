/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:30:00 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:21 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		count++;
	}
	return (destiny);
}
