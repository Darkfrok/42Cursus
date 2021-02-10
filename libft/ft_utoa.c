/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:37:32 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/10 12:44:16 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	long	nbr;
	size_t	len;
	char	*new;

	nbr = n;
	len = (nbr > 0) ? 0 : 1;
	nbr = (nbr > 0) ? nbr : -nbr;
	while (n)
		n = len++ ? n / 10 : n / 10;
	new = (char *)malloc(sizeof(new) * len + 1);
	if (!new)
		return (NULL);
	*(new + len--) = '\0';
	while (nbr > 0)
	{
		*(new + len--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (len == 0 && new[1] == '\0')
		*(new + len) = '0';
	if (len == 0 && new[1] != '\0')
		*(new + len) = '-';
	return (new);
}
