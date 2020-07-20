/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada </var/mail/cquezada>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:18:06 by cquezada          #+#    #+#             */
/*   Updated: 2020/07/20 13:51:01 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	fbzero(void *s, size_t n)
{
	char	*str;
	size_t	count;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
}
