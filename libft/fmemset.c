/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmemset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada </var/mail/cquezada>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:25:04 by cquezada          #+#    #+#             */
/*   Updated: 2020/07/20 12:27:46 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*fmemset(void *s, int c, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = c;
		count++;
	}
	return (str);
}
