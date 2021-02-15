/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:17:39 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/15 17:26:31 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_itohex(unsigned int decimalnum)
{
	unsigned int	quotient;
	unsigned int	remainder;
	char			*str;
	unsigned int	j;
	char			hexadecimalnum[100];

	j = 0;
	quotient = decimalnum;
	while (j < 100)
		hexadecimalnum[j++] = '\0';
	j = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	str = ft_strdup(hexadecimalnum);
	ft_invertstr(str);
	return (str);
}

char	*ft_longtohex(unsigned long decimalnum)
{
	unsigned long	quotient;
	unsigned long	remainder;
	char			*str;
	unsigned long	j;
	char			hexadecimalnum[100];

	j = 0;
	quotient = decimalnum;
	while (j < 100)
		hexadecimalnum[j++] = '\0';
	j = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	str = ft_strdup(hexadecimalnum);
	ft_invertstr(str);
	return (str);
}
