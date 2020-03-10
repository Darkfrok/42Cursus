/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:49:23 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:56 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dest[len] && len < size)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dest[len] = src[len - i];
		len += 1;
	}
	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
