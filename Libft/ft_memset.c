/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:41:12 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:23 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*str;

	str = (char *)b;
	count = 0;
	while (count < len)
	{
		str[count] = c;
		count++;
	}
	return (str);
}
